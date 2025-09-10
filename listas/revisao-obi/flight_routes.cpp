#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link : https://cses.fi/problemset/task/1682/

void bfs(const int<int<int>> adj, int ini, int<bool> &visited){
    queue<int> q; 
    q.push(ini);
    while(!q.empty()){
        int v = q.front(); q.pop();
        visited[v] = true;
        for(auto &u: adj[v]){
            if(!visited[u]) q.push(u);
        }   
    }
}



signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m; 
    int<int<int>> adj1(n,int<int>()), adj2(n,int<int>());
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b; 
        a--, b--; 
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    int<bool> visited(n, false);
    bfs(adj1, 0, visited);
    for(int i=0;i<n;i++){
        if(!visited[i]) {
            cout << "NO\n" << 1 << " " << i+1;
            return 0;
        }
    }
    visited.assign(n,false);
    cout << endl;
    bfs(adj2,0,visited);
    for(int i=0;i<n;i++){
        if(!visited[i]) {
            cout << "NO\n" << i+1 << " " << 1;
            return 0;
        }
    }
    cout << "YES" << "\n"; 
    return 0;
}