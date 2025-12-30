#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int n; 
vector<vector<int>> capacity; 
vector<vector<int>> adj;

int bfs(int s, int t, vector<int> &parent){
    fill(parent.begin(), parent.end(),-1);
    parent[s] = -2; 
    queue<pair<int,int>> q;
    q.push({s,LLONG_MAX});
    while(!q.empty()){
        auto [cur,flow] = q.front(); q.pop();
        for(int next: adj[cur]){
            if(parent[next] == -1 && capacity[cur][next]){
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if(next == t)
                    return new_flow;
                q.push({next, new_flow});
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
        int cur = t;
        while(cur != s){
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}
// será chamado depois do edmonds ter sido feito

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}