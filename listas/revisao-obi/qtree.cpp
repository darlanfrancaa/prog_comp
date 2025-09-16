#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int MAXN = 1e5+5;

//link: https://www.spoj.com/problems/QTREE2/

vector<pii> adj[MAXN];
int depth[MAXN];
int parent[MAXN];
pii dp[MAXN][LOG+1];


void dfs(int v,int p,int custo, int d){
    depth[v] = d; 
    parent[v] = p;
    dp[v][0] = {p, custo};

    for(auto node: adj[v]){
        if(node.first != p){
            dfs(node.first, v, node.second, d+1);
        }
    }
}

void fill(int n){
    for(int j=1;j<=LOG;j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1].first != -1){
                dp[i][j] = {dp[dp[i][j-1].first][j-1].first,
                                dp[dp[i][j-1].first][j-1].second + dp[i][j-1].second};
            } else { 
                dp[i][j] = {-1,0};
            }
        }
    }
}

pii up(int v, int k){
    int sum = 0;
    for(int j=LOG;j>=0;j--){
        if(k & (1 << j)){
            sum += dp[v][j].second;
            v = dp[v][j].first;
        }
    }
    return {v,sum};
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    int diff = depth[u] - depth[v];
    u = up(u,diff).first;
    if(u == v) return u;

    for(int j=LOG;j>=0;j--){
        if(dp[u][j].first != -1 && dp[u][j].first != dp[v][j].first){
            u = dp[u][j].first; 
            v = dp[v][j].first;
        }
    }
    return parent[u];
}

pii dist(int u, int v){
    int l = lca(u,v);
    int du = depth[u], dv = depth[v], dl = depth[l];
    int sum = 0; 
    sum += up(v, dv - dl).second;
    sum += up(u, du - dl).second;
    return {du + dv - 2*dl, sum};
}

int subir_caminho(int a, int b, int k){
    k--;
    int l = lca(a,b);
    int distancia = depth[a] - depth[l];
    if(distancia >= k){
        a = up(a,k).first; 
        return a;
    } else { 
        int distancia2 = k - distancia;
        int distancia_b = depth[b] - depth[l];
        b = up(b, distancia_b - distancia2).first;
        return b;
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        depth[i] = 0;
        for (int j = 0; j <= LOG; ++j) {
            dp[i][j] = {-1, 0};
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1, -1, 0, 0);
    fill(n);

    string command;
    while (cin >> command && command != "DONE") {
        if (command == "DIST") {
            int u, v;
            cin >> u >> v;
            cout << dist(u, v).second << "\n";
        } else if (command == "KTH") {
            int u, v, k;
            cin >> u >> v >> k;
            cout << subir_caminho(u,v,k) << "\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}