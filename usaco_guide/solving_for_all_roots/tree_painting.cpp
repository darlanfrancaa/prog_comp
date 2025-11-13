#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 2e5+1;
vector<int> adj[MAXN];
map<pii,pii> dp; 
// a dp vai salvar um par u,v e o valor (pontuação, tamanho)

pii solve(int u, int p){
    if(dp.count({p,u})) return dp[{p,u}];
    int curr_pont = 0; 
    int curr_tam = 1; 

    for(int v: adj[u]){
        if(v!= p){
            pii res = solve(v,u);
            curr_pont += res.first; 
            curr_tam += res.second;
        }
    }

    int total = curr_pont + curr_tam; 
    return dp[{p,u}] = {total, curr_tam};
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int maximo = 0; 
    

    for(int i=1;i<=n;i++){
        pair<int,int> res = solve(i,0);
        maximo = max(maximo, res.first);
    }
    cout << maximo << "\n";
    return 0;
}