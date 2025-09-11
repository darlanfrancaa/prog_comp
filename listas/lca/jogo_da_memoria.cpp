#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int N = 50004;
const int LOG = 20;

//link: https://olimpiada.ic.unicamp.br/pratique/p1/2014/f2/memoria/

vector<int>  adj[N]; 
int dp[N][LOG]; 
int parent[N]; 
int depth[N];
int n;
void dfs(int v, int p, int d){
    parent[v] = p;
    depth[v] = d; 
    dp[v][0] = p;

    for(auto node : adj[v]){
        if(node != p){
            dfs(node,v,d+1);
        }
    }
}

void fill_dp(){
    for(int j = 1;j<=LOG-1;j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1] != -1) dp[i][j] = dp[dp[i][j-1]][j-1];
            else dp[i][j] = -1;
        }
    }
}

int up(int v, int k){
    for(int j = LOG-1; j >= 0; --j){
        if(k & (1 << j)){
            v = dp[v][j];
        }
    }
    return v;
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    
    int diff = depth[u] - depth[v];
    u = up(u,diff);

    if(u == v) return u;

    for(int j=LOG - 1;j>=0;--j){
        if(dp[u][j] != -1 && dp[u][j] != dp[v][j]){
            u = dp[u][j];
            v = dp[v][j];
        }
    }
    return parent[u];
}

int distancia(int u, int v){
    int lo_ca = lca(u,v);
    return depth[u] + depth[v] - 2 * depth[lo_ca];
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n; 

    map<int, vector<int>> mapa;
    for(int i=1;i<=n;i++){
        int a; cin >> a; 
        mapa[a].push_back(i);
    }
    for(int i=0;i<n-1;i++){
        int a, b; cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    dfs(1,-1,0);
    fill_dp();
    int sum = 0; 
    for(auto const &[k, par]: mapa){
        sum += distancia(par[0], par[1]);
    }
    cout << sum << "\n";
    return 0;
}