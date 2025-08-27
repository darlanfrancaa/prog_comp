#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct Edge { 
    int v,c, flow;
};
int n,m; 
vector<vector<Edge>> adj;

int dijkstra(int min_flow){ 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> cost(n,INT_MAX);
    cost[0] = 0; 
    pq.push({0,0});
    while(!pq.empty()){
        auto [a_cost, node] = pq.top(); pq.pop(); 
        if(a_cost > cost[node]) continue; 
        for(auto &v: adj[node]){
            if(v.flow < min_flow) continue; 
            if(cost[v.v] > a_cost + v.c){
                pq.push({cost[v.v] = a_cost + v.c, v.v});
            }
        }
    }
    if(cost[n-1] == INT_MAX) return -1;
    return cost[n-1];
}


int main() {
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; 
    adj.resize(n);
    vector<int> flows;
    for(int i =0;i<m;i++){
        int a,b,c,f; cin >> a >> b >> c >> f; 
        a--; b--; 
        flows.push_back(f);
        adj[a].push_back({b,c,f});
        adj[b].push_back({a,c,f});
    }
    int ans = INT_MIN;  
    for(auto min_flow: flows){ 
        int ret = dijkstra(min_flow);
        if(ret == -1) continue;
        double r = double(min_flow) / double (ret);
        ans = max(ans, (int)(r * 1e6));
    }
    cout << ans << "\n";
}