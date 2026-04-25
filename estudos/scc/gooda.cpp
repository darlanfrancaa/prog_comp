#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://www.spoj.com/problems/GOODA/
vector<bool> visited;


void dfs(int v, vector<vector<int>> &adj, vector<int> &output){
    visited[v] = true;    
    for(auto u: adj[v]){
        if(!visited[u]) dfs(u,adj,output);
    }
    output.push_back(v);
}

vector<int> sum_roots;
vector<int> vals;
vector<vector<int>> adj;
vector<vector<int>> components; 
vector<vector<int>> adj_cond;
vector<int> roots;
void scc(vector<vector<int>> &adj, vector<vector<int>> &components, vector<vector<int>> &adj_cond){
    int n = adj.size(); 
    visited.assign(n, false);
    components.clear(), adj_cond.clear();
    vector<int> order; 

    for(int v=0;v<n;v++){
        if(!visited[v]) dfs(v,adj,order);
    }

    vector<vector<int>> adj_rev(n,vector<int>());
    for(int v=0;v<n;v++){
        for(auto u: adj[v]){
            adj_rev[u].push_back(v);
        }
    }
    visited.assign(n, false);
    reverse(order.begin(), order.end());
    for(auto v: order){
        if(!visited[v]){
            vector<int> component; 
            dfs(v,adj_rev,component);
            components.push_back(component);
            int root = v; 
            for(auto u: component){
                roots[u] = root; 
                sum_roots[root] += vals[u];
            }
        }
    }
    adj_cond.assign(n,{}); 
    for(int v=0;v<n;v++){
        for(auto u: adj[v]){
            if(roots[u] != roots[v]) adj_cond[roots[v]].push_back(roots[u]);
        }
    }
}
int e;
vector<int> max_dist;
int dfs_dist(int v, vector<vector<int>> &adj, vector<int> &vals){
    if(visited[v]) return max_dist[v];
    visited[v] = true; 
    if(v == roots[e]){
        return max_dist[v] = vals[v];
    }
    int maximo = LLONG_MIN;
    for(auto u: adj[v]){
        if(!visited[u]) dfs_dist(u, adj, vals);
        maximo = max(maximo, max_dist[u]);
    }
    max_dist[v] = maximo + vals[v];
    return max_dist[v]; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,s; cin >> n >> m >> s >> e; 
    s--; e--;
    vals.resize(n); sum_roots.resize(n); adj.resize(n); max_dist.resize(n,0); roots.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> vals[i];
    }
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }
    
    scc(adj, components, adj_cond);
    visited.assign(n,false);
    // for(auto component: components){
    //     cout << "estou em componente nova \n";
    //     for(auto v: component){
    //         cout << v;
    //     }
    //     cout << "\n";
    // }
    cout << dfs_dist(roots[s],adj_cond,sum_roots);
    


    return 0;
}