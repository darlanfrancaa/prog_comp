#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/contest/776/problem/D

struct TwoSat{
    int n; 
    vector<vector<int>> adj, adj_rev; 
    vector<int> order, comp; 
    vector<bool> vis, ans; 

    TwoSat(int n): n(n), adj(2*n), adj_rev(2*n), comp(2*n, -1), vis(2*n, false), ans(n) {}
    void add_clause(int u, bool is_neg_u, int v, bool is_neg_v){
        // adicionando que u or v
        int nu = 2 * u + (is_neg_u ? 1 : 0);
        int nv = 2 * v + (is_neg_v ? 1 : 0);

        int neg_u = nu ^ 1;
        int neg_v = nv ^ 1;
        adj[neg_u].push_back(nv);
        adj_rev[nv].push_back(neg_u);

        adj[neg_v].push_back(nu);
        adj_rev[nu].push_back(neg_v);
    }

    void dfs1(int u){
        vis[u] = true; 
        for(auto node: adj[u]){
            if(!vis[node]) dfs1(node);
        }
        order.push_back(u);
    }

    void dfs2(int u, int id){
        comp[u] = id;
        for(auto v: adj_rev[u]){
            if(comp[v] == -1) dfs2(v, id);
        }   
    }

    bool solve(){
        order.clear() ;
        fill(vis.begin(), vis.end(), false);
        for(int i=0;i<2*n;i++){
            if(!vis[i]) dfs1(i);
        }
        fill(comp.begin(), comp.end(), -1);
        int id = 0; 
        for(int i = 2*n -1; i>=0;i--){
            int u = order[i];
            if(comp[u] == -1) dfs2(u, id++);
        }

        for(int i=0;i<n;i++){
            int pos = 2*i;
            int neg = 2*i + 1;
            if(comp[pos] == comp[neg]) return false;
            ans[i] = comp[pos] > comp[neg];
        }
        return true;

    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    vector<int> comeco(n);
    for(int i=0;i<n;i++){
        cin >> comeco[i];
    }
    vector<vector<int>> portas(n);
    for(int i=0;i<m;i++){
        int x; cin >> x; 
        for(int j=0; j<x;j++){
            int qrt; cin >> qrt; qrt--; 
            portas[qrt].push_back(i);
        }
    }
    TwoSat solver(m);
    for(int i=0;i<n;i++){
        int a = portas[i][0];
        int b = portas[i][1];
        if(comeco[i] == 1){
            solver.add_clause(a, true, b, false);
            solver.add_clause(a, false, b, true);
        } else {
            solver.add_clause(a, false, b, false);
            solver.add_clause(a, true, b, true);
        }
    }

    if (solver.solve()){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}