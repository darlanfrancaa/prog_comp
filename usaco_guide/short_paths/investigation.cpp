#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    vector<vector<pair<int,ll>>> adj(n);
    for(int i=0;i<m;i++){
        int a,b,w; cin >> a >> b >> w; 
        a--;b--; 
        adj[a].push_back({b,w});
    }
    vector<ll> dist(n,LLONG_MAX),num(n),minf(n,LLONG_MAX),maxf(n,LLONG_MIN);
    vector<bool> vis(n);
    int start = 0; 
    dist[start] = 0; num[start] = 1;minf[start] = 0, maxf[start] = 0;
    using T = pair<ll,int>;
    priority_queue<T, vector<T>, greater<T>> pq; 
    pq.push({0,start});
    while(!pq.empty()){
        auto [cdist, node] = pq.top(); pq.pop();
        if(vis[node] || cdist > dist[node]) continue; 
        vis[node] = true;
        for(auto &[vertice, distancia] :adj[node]){
            ll dist_atual = cdist + distancia;
            if(dist_atual == dist[vertice]){
                num[vertice] = (num[vertice] + num[node]) % MOD;
                minf[vertice] = min(minf[vertice], minf[node] + 1);
                maxf[vertice] = max(maxf[vertice], maxf[node] + 1);
            } else if ( dist_atual < dist[vertice]){
                num[vertice] = num[node]; 
                minf[vertice] = minf[node] + 1; 
                maxf[vertice] = maxf[node] + 1;
                pq.push({dist[vertice] = dist_atual, vertice});
            }
        }
    }
    cout << dist[n-1] << " " << num[n-1] << " " << minf[n-1] << " " << maxf[n-1] << "\n";
    return 0;
}