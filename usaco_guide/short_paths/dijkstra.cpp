#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    vector<vector<pair<int,int>>> vizinhos(n); 
    for(int i=0;i<m;i++){
        int a, b , c; cin >> a >> b >> c; 
        vizinhos[a-1].push_back({b-1,c});
    }

    vector<ll> dist(n, LLONG_MAX);
    using T = pair<ll,int>; 
    priority_queue<T, vector<T>, greater<T>> pq; 

    int start = 0; 
    dist[start] = 0; 
    pq.push({0,start});

    while(!pq.empty()){
        const auto [cdist, node] = pq.top(); pq.pop(); 
        if(cdist != dist[node]) continue;
        for(auto &i: vizinhos[node]){ 
            if(cdist + i.second < dist[i.first]){ 
                pq.push({dist[i.first] = cdist + i.second, i.first});
            }
        }
    }

    for(int i=0;i<n-1;i++){
        cout << dist[i] << " ";
    }
    cout << dist[n-1] << "\n";
    return 0;
}