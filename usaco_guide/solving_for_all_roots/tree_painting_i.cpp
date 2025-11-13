#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 2e5+10;

vector<int> adj[MAXN];
int sz[MAXN], dp[MAXN]; 
int ans = 0; 
int n;

void dfs1(int u, int p){
    sz[u] = 1; 
    dp[u] = 0;

    for(int v:adj[u]){
        if(v != p){
            dfs1(v,u);
            sz[u] += sz[v];
            dp[u] += dp[v];
        }
    }
    dp[u] += sz[u];
}

void dfs2(int u, int p){
    ans = max(ans, dp[u]);
    for(int v: adj[u]){
        if(v != p){
            pii old_u = {dp[u],sz[u]};
            pii old_v = {dp[v],sz[v]};

            dp[u] -= (dp[v] + sz[v]);
            sz[u] -= sz[v];

            sz[v] += sz[u];
            dp[v] += dp[u] + sz[u];

            dfs2(v,u);
            tie(dp[u],sz[u]) = old_u;
            tie(dp[v], sz[v]) = old_v;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,0);
    dfs2(1,0);
    cout << ans << "\n";
    return 0;
}