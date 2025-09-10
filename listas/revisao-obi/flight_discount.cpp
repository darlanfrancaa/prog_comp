#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link : https://cses.fi/problemset/task/1195

struct T { 
    int dist; 
    int node; 
    bool used;
 
    bool operator<(const T &other) const {
        return dist > other.dist;
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    int<int<pii>> adj(n+1,int<pii>());
    for(int i=0;i<m;i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b,w});
    }

    int<int> dist_using(n+1,LLONG_MAX);
    int<int> dist_n_using(n+1,LLONG_MAX);
    int start = 1;
    priority_queue<T> pq; 
    pq.push({0,start,0});
    while(!pq.empty()){
        auto [cdist,v, used] = pq.top(); pq.pop();
        if(used && cdist > dist_using[v]) continue;
        if(!used && cdist > dist_n_using[v]) continue;
        if(used){
            for(auto &par: adj[v]){
                if(dist_using[par.first] > cdist + par.second){
                    pq.push({dist_using[par.first] = cdist + par.second, par.first, 1});
                }
            }
        } else {
            for(auto &par: adj[v]){
                if(dist_n_using[par.first] > cdist + par.second){
                    pq.push({dist_n_using[par.first] = cdist + par.second, par.first, 0});
                }
            }
            for(auto &par: adj[v]){
                if(dist_using[par.first] > cdist + (par.second/2)){
                    pq.push({dist_using[par.first] = cdist + (par.second/2), par.first, 1});
                }
            }
        }
    }
    cout << min(dist_using[n], dist_n_using[n]) << "\n";

    return 0;
}