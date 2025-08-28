#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    vector<vector<pair<int,ll>>> adj(n);
    for(int i=0;i<m;i++){
        int a,b,w; cin >> a >> b >> w; 
        a--;b--;
        adj[a].push_back({b,w});
    }
    vector<priority_queue<ll>> best(n);
    using T = pair<ll,int>; 
    priority_queue<T,vector<T>, greater<T>> pq; 
    int start = 0;
    best[start].push(0);
    pq.push({0,start});
    while(!pq.empty()){
        auto [cdist,node] = pq.top(); pq.pop();
        if(cdist > best[node].top()) continue; 
        for(auto &i: adj[node]){
            ll distancia = cdist + i.second;
            if(best[i.first].size() < k){
                best[i.first].push(distancia);
                pq.push({distancia, i.first});
            } else if (distancia < best[i.first].top()){
                best[i.first].pop();
                best[i.first].push(distancia);
                    pq.push({distancia, i.first});
            }
        }
    }
    vector<ll> ans; 
    while(!best[n-1].empty()){
        ll num = best[n-1].top(); best[n-1].pop(); 
        ans.push_back(num);
    }
    reverse(ans.begin(), ans.end());
    for(auto a: ans) cout << a << " ";
    return 0;
}