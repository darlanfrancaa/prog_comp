#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1684

struct TwoSat{
    int n;
    vector<vector<int>> adj, adj_rev; 
    vector<int> order, comp;
    vector<bool> ans, vis;

    TwoSat(int n): n(n), adj(2*n), adj_rev(2*n), comp(2*n, -1), vis(2*n, false), ans(n) {}

    void add_clause(int a, bool neg_a, int b, bool neg_b){
        // a ou b , 
        int node_a = 2*a + (neg_a ? 1 : 0);
        int node_b = 2*b + (neg_b ? 1 : 0);

        int neg_node_a = node_a ^ 1; 
        int neg_node_b = node_b ^ 1; 

        adj[neg_node_a].push_back(node_b);
        adj_rev[node_b].push_back(neg_node_a);

        adj[neg_node_b].push_back(node_a);
        adj_rev[node_a].push_back(neg_node_b);
    }

    void dfs1(int v){
        vis[v] = true; 
        for(auto u: adj[v]){
            if(!vis[u]) dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int id){
        comp[v] = id;
        for(auto u: adj_rev[v]){
            if(comp[u] == -1) dfs2(u,id);
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
        for(int i=2*n-1;i>=0;i--){
            int u = order[i];
            if(comp[u] == -1) dfs2(u, id++);
        }
        for(int i=0;i<n;i++){
            int pos = 2*i; 
            int neg = 2*i + 1;

            if(comp[pos] == comp[neg]) return false;
            ans[i] = (comp[pos] > comp[neg]);
        }
        return true;
    }

    void print_ans(){
        for(int i=0;i<n;i++){
            if(ans[i]) cout << "+ ";
            else cout << "- ";
        }
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    TwoSat sat(m);
    for(int i = 0;i<n;i++){
        char op1, op2; int num1, num2; 
        cin >> op1 >> num1 >> op2 >> num2; 
        num1--; num2--;
        if(op1 == '+' && op2 == '+') sat.add_clause(num1, false, num2, false);
        else if(op1 == '+' && op2 == '-') sat.add_clause(num1, false, num2, true);
        else if(op1 == '-' && op2 == '+') sat.add_clause(num1, true, num2, false);
        else if(op1 == '-' && op2 == '-') sat.add_clause(num1, true, num2, true);
    }
    if(sat.solve()) sat.print_ans(); 
    else cout << "IMPOSSIBLE\n";
    return 0;

}