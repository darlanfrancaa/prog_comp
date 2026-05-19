#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

void is_bridge(int v, int to){
    cout << "ponte";
}
int n; 
vector<vector<int>> adj; 

vector<bool> visited; 
vector<int> tin, low; 
int timer; 

void dfs(int v, int p = -1){
    visited[v] = true; 
    tin[v] = low[v] = timer ++;
    bool parent_skipped = false;  
    for(int to: adj[v]){
        if(to == p && !parent_skipped) {
            parent_skipped = true; 
            continue; 
        }
        if(visited[to]){
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to,v);
            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v]){
                is_bridge(v,to);
            } 
        }
    }
}

void find_bridges(){
    timer = 0; 
    visited.assign(n,false);
    tin.assign(n,-1);
    low.assign(n,-1);
    for(int i=0;i<n;i++){
        if(!visited[i]) dfs(i);
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}