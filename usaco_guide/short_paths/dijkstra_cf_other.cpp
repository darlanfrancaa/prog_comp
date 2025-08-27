#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
using pii = pair<int,int>; 



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    vector<vector<pair<int,ll>>> vizinhos(n);
    vector<int> parent(n,-1);
    for(int i=0;i<m;i++){
        int a, b;
        ll w; cin >> a >> b >> w; 
        a--;b--; 
        vizinhos[a].push_back({b,w});
        vizinhos[b].push_back({a,w});
    }
    vector<ll> dist(n,LLONG_MAX); 
    int start = 0; 
    dist[start] = 0;
    using T = pair<ll, int>; 
    priority_queue<T,vector<T>, greater<T>> pq; 
    pq.push({0, start});

    while(!pq.empty()){
        auto [cdist, node] = pq.top(); pq.pop();
        if(cdist > dist[node]) continue; 
        for(auto &v : vizinhos[node]){
            if(cdist+v.second < dist[v.first]){
                parent[v.first] = node;
                pq.push({dist[v.first] = cdist + v.second, v.first});
            }
        }
    }

    if(dist[n-1] == LLONG_MAX){
        cout << -1 << "\n"; 
        return 0;
    }
    vector<int> ans; 
    int atual = n-1; 
    while(atual != -1){
        ans.push_back(atual+1);
        if(atual == start) break;
        atual = parent[atual];
    }
    reverse(ans.begin(), ans.end());
    for(auto i: ans) cout << i << " "; 
    cout << "\n";
    return 0;


}