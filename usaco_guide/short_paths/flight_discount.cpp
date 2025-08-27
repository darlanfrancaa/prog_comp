#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct T { 
    ll dist; 
    int node; 
    bool used;

    bool operator<(const T &other) const {
        return dist > other.dist;
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m; 
    vector<vector<pair<int,ll>>> adj(n);
    for(int i=0;i<m;i++){
        int a,b,w; cin >> a >> b >> w; 
        a--;b--;
        adj[a].push_back({b,w});
    }
    vector<ll> dist_using(n,LLONG_MAX);
    vector<ll> dist_n_using(n,LLONG_MAX);
    int start = 0;
    dist_using[start] = dist_n_using[start] = 0;
    priority_queue<T> pq; 
    pq.push({0,start, false});
    while(!pq.empty()){
        auto [cdist, node, used] = pq.top(); pq.pop(); 
        if (used && cdist > dist_using[node]) continue;
        if (!used && cdist > dist_n_using[node]) continue;
        if(used){ 
            for(auto &i : adj[node]){
                if(dist_using[i.first] > cdist + i.second){
                    pq.push({dist_using[i.first] = cdist + i.second, i.first, true});
                }
            }
        } else {
            for(auto &i : adj[node]){
                if(dist_n_using[i.first] > cdist + i.second){
                    pq.push({dist_n_using[i.first] = cdist + i.second, i.first, false});
                }
                if(dist_using[i.first] > cdist + (i.second / 2)){
                    pq.push({dist_using[i.first] = cdist + (i.second/2), i.first, true});
                } 
            }
        }
    }
    cout << min(dist_n_using[n-1], dist_using[n-1]);
    return 0;
}