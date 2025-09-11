#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

const int N = 2e5 + 10;
const int LOG = 20;
int n;
vector<vector<int>> adj(N);
vector<int> parent(N);
vector<int> depth(N);
vector<vector<int>> dp(N,vector<int>(LOG, -1));

pair<int,int> bfs(int start){
    vector<int> dist(n+2, -1);
    queue<int> q; 
    dist[start] = 0;
    q.push(start);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto node: adj[v]){
            if(dist[node] == -1){
                dist[node] = dist[v] + 1;
                q.push(node);
            }
        }
    }
    int max_dist= -1;; 
    int node_max = start;
    for(int i=1;i<=n;i++){
        if(dist[i] > max_dist){
            max_dist = dist[i];
            node_max = i;
        }
    }
    return {node_max, max_dist};
}

pair<int,int> find_diameter(){
    auto [v1,_1] = bfs(1);
    auto [v2,_2] = bfs(v1);
    return make_pair(v1,v2);
}

void dfs(int v,int p, int d){
    parent[v] = p; 
    depth[v] = d; 
    dp[v][0] = p; 
    for(auto node: adj[v]){
        if(node != p) dfs(node,v, d+1);
    }
}

void fill_dp(){
    for(int j= 1; j< LOG;j++){
        for(int i = 1;i<=n;i++){
            if(dp[i][j-1] != -1) dp[i][j] = dp[dp[i][j-1]][j-1];
            else dp[i][j] = -1;
        }
    }
}

int up(int v, int k){
    for(int j=LOG-1;j>=0;--j){
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
    for(int j=LOG-1;j>=0;j--){
        if(dp[u][j] != -1 && dp[u][j] != dp[v][j]){
            u = dp[u][j];
            v = dp[v][j];
        }
    }
    return parent[u];
}

int dist(int u, int v){
    int node = lca(u,v);
    return depth[u] + depth[v]  - 2*depth[node];
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin >> n >> q; 
    for(int i=0;i<n-1;i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    auto [p1,p2] = find_diameter();
    dfs(1,-1,0);
    fill_dp();
    for(int i=0;i<q;i++){
        int v,d; cin >> v >> d;
        if(dist(v,p1) < dist(v,p2)) swap(p1,p2); // p1 tem a maior distância;
        if(dist(v,p1) < d) {
            cout << 0 << "\n";
            continue;
        } else { 
            int l = lca(v,p1);
            if(dist(v,l) >= d) { 
                cout << up(v,d) << "\n";
                continue;
            } else { 
                int total = dist(v,p1);
                cout << up(p1,total - d) << "\n";
                continue;
            }
        }
    }
    return 0;
}