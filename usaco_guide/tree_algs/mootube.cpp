#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
using pii = pair<int,int>;
int n;
vector<vector<pii>> adj;
vector<bool> visitado;
int contador, k;
 
void dfs(int v){
    visitado[v] = true;
    for(auto [node, relevancia]: adj[v]){
        if(!visitado[node] && relevancia >= k){
            contador++;
            dfs(node);
        }
    }
}

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin >> n >> q;
    adj.resize(n,vector<pii>());
    for(int i=0;i<n-1;i++){
        int a, b , relevancia; 
        cin >> a >> b >> relevancia;
        a--; b--;
        adj[a].push_back({b,relevancia});
        adj[b].push_back({a,relevancia});
    }
    
    for(int i=0;i<q;i++){
        int v; 
        cin >> k >> v;
        v--;
        visitado = vector<bool>(n);
        contador = 0;
        dfs(v);
        cout << contador << endl;
    }

    return 0;
}