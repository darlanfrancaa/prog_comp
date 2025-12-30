#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1694

const int MAXN = 510;

int n,m; 
vector<vector<int>> adj; 
int cap[MAXN][MAXN];
int orig_cap[MAXN][MAXN];

int bfs(int s, int t, vector<int>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2; 
    queue<pair<int,int>> q; 
    q.push({s,LLONG_MAX});
    while(!q.empty()){
        auto [curr, flow] = q.front(); q.pop();
        for (int node: adj[curr]){
            if(parent[node] == -1 && cap[curr][node]){
                parent[node] = curr;
                int new_flow = min(flow, cap[curr][node]);
                if(node == t) return new_flow;
                q.push({node, new_flow});
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0; 
    vector<int> parent(n); 
    int new_flow; 

    while(new_flow = bfs(s,t,parent)){
        flow += new_flow;
        int curr = t; 
        while(curr != s){
            int prev = parent[curr];
            cap[prev][curr] -= new_flow;
            cap[curr][prev] += new_flow;
            curr = prev;
        }
    }
    return flow;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; 
    adj.resize(n);
    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w; 
        u--; v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] +=w;
        orig_cap[u][v] +=w;
    }

    cout << max_flow(0,n-1) << "\n";

    return 0;
}