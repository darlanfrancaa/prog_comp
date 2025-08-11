#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m; 
    vector<vector<int>> adj(n,vector<int>());
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b; 
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int minimo = INT_MAX;
    for(int i=0;i<n;i++){
        vector<int> dist(n,-1), pai(n);
        dist[i] = 0; 
        queue<int> q; 
        q.push(i); 
        while(!q.empty()){
            int v = q.front();q.pop();
            for(auto u: adj[v]){
                if(dist[u]==-1) {
                    dist[u] = dist[v] + 1;
                    pai[u] = v;
                    q.push(u);
                }
                else { 
                    if(u != pai[v]) {
                        minimo = min(minimo, dist[u]+dist[v]+1);
                        break;
                    }
                }
            }
        }
    }
    if(minimo == INT_MAX) cout << -1 << endl;
    else cout << minimo << endl;
    return 0;
}