#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin >> n >> m >> k; 
    vector<vector<pii>> adj(n);
    for(int i=0;i<m;i++){
        int a,b, w; cin >> a >> b >> w; 
        adj[a].push_back({b,w});
    }
    vector<priority_queue<int>> best(n);
    using T = pair<int,int>; 
    priority_queue<T,vector<T>, greater<T>> pq;
    int start = 0; 
    best[start].push(0);
    pq.push({start,0});
    while(!pq.empty()){
        auto [cdist, node] = pq.top(); pq.pop(); 
        if(cdist > best[node].top()) continue;
        for(auto &i: adj[node]){
            int distance = cdist + i.second;
            if(best[i.first].size() < k){
                best[i.first].push(distance);
                pq.push({distance,i.first});
            } else if( distance < best[i.first].top()){
                best[i.first].pop();
                best[i.first].push(distance);
                pq.push({distance, i.first});
            }
        }
    }
    vector<int> ans; 
    while(!best[n-1].empty()){
        int num = best[n-1].top(); best[n-1].pop(); 
        ans.push_back(num);
    }
    reverse(ans.begin(), ans.end());
    for(auto a: ans) cout << a << " ";
    return 0;
}