#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link : https://usaco.org/index.php?page=viewproblem2&cpid=491#

vector<vector<int>> adj;

vector<int> bfs(int start, int n){
    vector<int> dist(n+1, LLONG_MAX);
    dist[start] = 0;
    queue<int> q; 
    q.push(start);
    while(!q.empty()){
        int v = q.front(); q.pop(); 
        for(auto node: adj[v]){
            if(dist[node] == LLONG_MAX){
                dist[node] = dist[v] + 1; 
                q.push(node);
            }
        }
    }
    return dist;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    int b, e, p, n , m; 
    cin >> b >> e >> p >> n >> m; 
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> dist1 = bfs(1,n);
    vector<int> dist2 = bfs(2,n);
    vector<int> distb = bfs(n,n);
    int minimo = LLONG_MAX; 
    for(int i=1;i<=n;i++){
        int val = dist1[i] * b + dist2[i] * e + distb[i]* p;
        minimo = min(minimo, val);
    }
    cout << minimo << "\n";
    return 0;
}