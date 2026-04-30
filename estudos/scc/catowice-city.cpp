// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj, adj_rev, components;
vector<int> roots;
vector<bool> visited;
// orderna topologicamente um grafo adj, no vetor order
void top_order(int v, vector<vector<int>>&adj, vector<int> &order){
    visited[v] = true; 
    for(auto u: adj[v]){
        if(!visited[u]) top_order(u, adj, order);
    }
    order.push_back(v);
}
 
void scc(vector<vector<int>> &adj, vector<vector<int>> &comps){
    comps.clear(); visited.clear(); roots.clear(); adj_rev.clear();
    vector<int> order;
    int n = adj.size(); visited.assign(n,false);
    roots.assign(n,-1);
    for(int i=0;i<n;i++) if(!visited[i]) top_order(i, adj, order);
    adj_rev.assign(n,{});
    for(int i=0;i<n;i++){
        for(auto u: adj[i]){
            adj_rev[u].push_back(i);
        }
    }
    visited.assign(n,false);
    reverse(order.begin(), order.end());
    for(auto u: order){
        if(!visited[u]){
            vector<int> new_comp;
            top_order(u, adj_rev, new_comp);
            comps.push_back(new_comp);
            int root = u; 
            for(auto v: new_comp){
                roots[v] = root;
            }
        } 
    }
}
 
void solve(){
    adj.clear(); components.clear();
    int n, m; cin >> n >> m; 
    adj.assign(n,{});
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b;
        a--;b--;
        adj[b].push_back(a); // criando um grafo direcionado para o grafo
    }
    scc(adj, components);
    // cout << "ans\n";
    if(components.size() == 1){
        cout << "No\n"; 
        return;
    }
    cout << "Yes\n" ;
    int seg_comp = components[1][0];
    visited.assign(n,false);
    vector<int> ans;
    top_order(seg_comp, adj, ans); 
    int qtd = ans.size(); 
    cout << n - ans.size() << " " << ans.size() << "\n";
    for(int i=0;i<n;i++){
        if(!visited[i]) cout << i+1 << " ";
    }
    cout << "\n"; 
    for(int i=0;i<n;i++){
        if(visited[i]) cout << i+1 << " ";
    }
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        solve();
        // string line; cin >> line;
    }
    return 0;
}