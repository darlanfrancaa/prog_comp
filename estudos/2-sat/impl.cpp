#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

struct TwoSat{
    int n; 
    vector<vector<int>> adj, adj_rev;
    vector<int> order,comp; 
    vector<bool> vis, ans;

    TwoSat(int n): n(n), adj(2*n), adj_rev(2*n), comp(2*n,-1), vis(2*n, false), ans(n){};

    void add_clause(int u, bool neg_u, int v, bool neg_v){
        int node_u = 2 * u + (neg_u ? 1 : 0);
        int node_v = 2 * v + (neg_v ? 1 : 0);

        int neg_node_u = node_u ^ 1;
        int neg_node_v = node_v ^ 1; 

        adj[neg_node_u].push_back(node_v);
        adj_rev[node_v].push_back(neg_node_u);

        adj[neg_node_v].push_back(node_u);
        adj_rev[node_u].push_back(neg_node_v);
    }

    void dfs1(int u){
        vis[u] = true; 
        for(int v: adj[u]){
            if(!vis[v]) dfs1(v);
        }
        order.push_back(u);
    }

    void dfs2(int u, int id){
        comp[u] = id;
        for(int v: adj_rev[u]){
            if(!vis[v]) dfs2(v, id);
        }
    }

    bool solve(){
        order.clear();
        fill(vis.begin(), vis.end(), false);
        for(int i=0;i<2*n;i++){
            if(!vis[i]) dfs1(i);
        }
        fill(comp.begin(), comp.end(), -1);
        int id = 0; 
        for(int i=2*n-1; i>=0;--i){
            int u = order[i];
            if(comp[u] == -1) dfs2(u, id++);
        }
        for(int i=0;i<n;i++){
            int no_pos = 2*i; 
            int no_neg = 2*i + 1; 

            if(comp[no_pos] == comp[no_neg]) return false; 
            ans[i] = comp[no_pos] > comp[no_neg];
        }
    }

};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}