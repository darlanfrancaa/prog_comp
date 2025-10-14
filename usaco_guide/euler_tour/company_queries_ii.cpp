#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int LOGN = 21;

vector<int> parent, depth; 
vector<vector<int>> dp;
vector<vector<int>> adj;

void dfs(int p, int v, int d){
    parent[v] = p;
    depth[v] = d; 
    dp[v][0] = p;
    for(auto node: adj[v]){
        if(node != p){
            dfs(v,node,d+1);
        }
    }
}

void fill_dp(int n){
    for(int j=1; j< LOGN;j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1] != -1) dp[i][j] = dp[dp[i][j-1]][j-1];
            else dp[i][j] = -1;
        }
    }
}

int up(int v, int k){
    for(int j= LOGN - 1; j>=0;j--){
        if(k & (1 << j)){
            if(v == -1) return -1;
            v = dp[v][j];
        }
    }
    return v;
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    int diff = depth[u] - depth[v];
    u = up(u, diff);

    if(u == v) return u; 
    for(int j=(LOGN-1);j>=0;j--){
        if(dp[u][j] != -1 && dp[u][j] != dp[v][j]){
            u = dp[u][j];
            v = dp[v][j];
        }
    }
    return parent[u];
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    parent.resize(n+1); 
    depth.resize(n+1); 
    dp.resize(n+1,vector<int> (LOGN, -1));
    adj.resize(n+1);
    for(int i=2;i<=n;i++){
        int a; cin >> a; 
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    dfs(-1,1,0);
    fill_dp(n);
    while(q--){
        int u, v; cin >> u >> v;
        cout << lca(u,v) << "\n";
    }
    
    return 0;
}