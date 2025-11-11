#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

const int MAX_VAL = 100; 
const int MAXN = 2 * 5e3;

const vector<int> PRIMES = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                            43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
class Primos{
private:
    vector<vector<int>> fatores_primos;
public: 
    Primos(int n) : fatores_primos(n+1){
        for(int i=2 ; i <= n;i++){
            for(int p:PRIMES){
                if(i % p == 0) fatores_primos[i].push_back(p);
            }
        }
    }

    const vector<int> &get_fatores(int n) {return fatores_primos[n];};
} factors(MAXN);

class Arvore{
private: 
    const vector<vector<int>> &adj;
    const vector<int> &valores;
    vector<vector<int>> custo_minimo; 
    vector<map<int,int>> custo_por_fator;

    void dfs(int at, int prev){
        custo_minimo[at] = vector<int>(MAXN + 1);
        for(int i=2;i<= MAXN;i++){
            if(i != valores[at]) custo_minimo[at][i] = i;
            if(factors.get_fatores(i).empty()) custo_minimo[at][i] = LLONG_MAX;
        }

        for(auto v: adj[at]){
            if(v == prev) continue;
            dfs(v, at);
            for(int i=2;i<=MAXN;i++){
                if(factors.get_fatores(i).empty()) continue;
                int minimo = LLONG_MAX;
                for(int p: factors.get_fatores(i)){
                    minimo = min(minimo, custo_por_fator[v][p]);
                }
                custo_minimo[at][i] += minimo;
            }
        }

        for(int p: PRIMES){
            int minimo_p = LLONG_MAX;
            for(int i=p;i<=MAXN;i+=p){
                minimo_p = min(minimo_p, custo_minimo[at][i]);
            }
            custo_por_fator[at][p] = minimo_p;
        }
    }

public: 
    Arvore(const vector<vector<int>> &adj, const vector<int> &valores): adj(adj), valores(valores), custo_minimo(adj.size()), custo_por_fator(adj.size()){
        dfs(0,0);
    }

    int ans() const{
        int ret = LLONG_MAX;
        for(int i=2; i<= MAXN;i++){
            ret = min(ret, custo_minimo[0][i]);
        } 
        return ret;
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> valores(n);
    for(auto &a: valores) cin >> a; 
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v; 
        u--;v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << Arvore(adj,valores).ans() << "\n";
    return 0;
}