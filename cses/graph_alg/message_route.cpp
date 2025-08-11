#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    vector<int> dist(n+1, INT_MAX), parent(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> fila; 
    dist[1] = 0;
    fila.push(1);
    while(!fila.empty()){
        int x = fila.front(); fila.pop();
        for(auto v: adj[x]){
            if(dist[v] == INT_MAX){
                dist[v] = dist[x] + 1;
                parent[v] = x;
                fila.push(v);
            }
        }
    }
    if(dist[n] == INT_MAX) cout << "IMPOSSIBLE" << endl;
    else {
        cout << dist[n] + 1 << endl;
        vector<int> ans = {n};
        while(ans.back() != 1) ans.push_back(parent[ans.back()]);
        reverse(ans.begin(), ans.end());
        for(auto valor : ans) cout << valor << " "; 

    }
    return 0;
}