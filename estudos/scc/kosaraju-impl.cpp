#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

vector<bool> visited; 

void dfs(int v, vector<vector<int>> &adj, vector<int> &output){
    visited[v] = true;
    for(auto u: adj[v]){
        if(!visited[u]) dfs(u, adj, output);
    }
    output.push_back(v);
}

void scc(vector<vector<int>> &adj, vector<vector<int>> &components, vector<vector<int>> &adj_cond){
    int n = adj.size();
    visited.assign(n, false);
    components.clear(); adj_cond.clear();
    vector<int> order; 

    for(int i=0;i<n;i++)
        if(!visited[i]) dfs(i,adj,order);

    vector<vector<int>> adj_rev(n);
    for(int v=0;v<n;v++)
        for(int u: adj[v])
            adj_rev[u].push_back(v);
    visited.assign(n,false);
    reverse(order.begin(), order.end());
    vector<int> roots(n,0);
    
    for(auto v:order){
        if(!visited[v]){
            vector<int> component;
            dfs(v,adj_rev, component);
            components.push_back(component);
            int root = v;
            for(auto u: component){
                roots[u] = root;
            }
        }
    }

    adj_cond.assign(n,{});
    for(int v=0;v<n;v++){
        for(auto u: adj[v]){
            if(roots[u]!=roots[v]){
                adj_cond[roots[v]].push_back(roots[u]);
            }
        }
    }
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    return 0;
}