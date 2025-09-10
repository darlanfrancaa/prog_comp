#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

struct Aresta{
    int a, b, w; 
};


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,c,k; 
    while(true){
        cin >> n >> m >> c >> k; 
        if(n == 0 && m == 0 && c == 0 && k ==0) break;
        vector<vector<pii>> adj(n);
        vector<vector<int>> adj_matrix(n, std::vector<int>(n, -1)); 

        for (int i = 0; i < m; ++i) {
            int u, v, p;
            std::cin >> u >> v >> p;
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
            adj_matrix[u][v] = p;
            adj_matrix[v][u] = p;
        }
        vector<int> custo_rota(c, 0);
        for (int i = c - 2; i >= 0; --i) {
            custo_rota[i] = custo_rota[i + 1] + adj_matrix[i][i + 1];
        }

        vector<int> dist(n, LLONG_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;
            
            if (u < c) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int peso = edge.second;
                if (dist[u] + peso < dist[v]) {
                    pq.push({dist[v] = dist[u] + peso, v});
                }
            }
        }
        
        int ans = LLONG_MAX;
        for (int i = 0; i < c; ++i) {
            if (dist[i] != LLONG_MAX) {
                ans = std::min(ans, dist[i] + custo_rota[i]);
            }
        }
        
        std::cout << ans << "\n";
    }
    return 0;
}