#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
ll N = 1e5+10; ll K = 22;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,k; cin >> n >> m >> k; 
    vector<ll> profits(n + 1, 0);
    for(int i = 2; i <= n; ++i) {
        cin >> profits[i];
    }
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i=0;i<m;i++){
        ll a,b,w; cin >> a >> b >> w; 
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    vector<vector<ll>> custos(n+1, vector<ll>(k+1,LLONG_MAX));
    using T = tuple<ll,ll,ll>; // dist, vertice, reputação atual;
    priority_queue<T,vector<T> , greater<T>> pq; 
    custos[1][0] = 0;
    pq.push({0,1,0});
    while(!pq.empty()){
        auto [cdist, node, rep] = pq.top(); pq.pop();
        if(custos[node][rep] < cdist) continue; 
        for(auto &par: adj[node]){
            if(rep < k){ 
                if(custos[par.first][rep+1] > cdist + par.second){
                    pq.push({custos[par.first][rep+1] = cdist + par.second, par.first, rep+1});
                }
            } 
            if(rep == k) { 
                if(custos[par.first][k] > cdist + par.second){
                    pq.push({custos[par.first][k] = cdist + par.second, par.first, k});
                }
                if(custos[par.first][0] > cdist){
                    pq.push({custos[par.first][0] = cdist , par.first ,0});
                }
            }
                
        }
    }

    ll ans = -1; 
    for(int i=2;i<=n;i++){
        ll dist = custos[i][k];
        if(dist != LLONG_MAX){
            ll lucro = profits[i] - dist;
            if(lucro > 0){
                ans = max(ans, lucro);
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}