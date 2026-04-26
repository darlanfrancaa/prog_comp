#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1686
vector<int> t_in, t_low, roots, st;
int timer = 0; 
vector<int> val, sum_comp;
vector<bool> visited;
vector<vector<int>> adj, components, adj_cond;
void top_order(int v, vector<vector<int>> &adj, vector<int> &order){
    visited[v] = true;
    for(auto u: adj[v]){
        if(!visited[u]) top_order(u,adj, order);
    }
    order.push_back(v);
}

void dfs(int v, vector<vector<int>> &adj, vector<vector<int>> &components){
    t_in[v] = t_low[v] = timer++; 
    st.push_back(v);
    for(auto u: adj[v]){
        if(t_in[u] == -1){
            dfs(u,adj,components);
            t_low[v] = min(t_low[v], t_low[u]);
        } else if(roots[u] == -1){
            t_low[v] = min(t_low[v], t_in[u]);
        }
    }

    if(t_in[v] == t_low[v]){
        vector<int> component;
        while(true){
            int u = st.back(); st.pop_back();
            sum_comp[v] += val[u];
            roots[u] = v; 
            component.push_back(u);
            if(u == v) break;
        }
        components.push_back(component);
    }
}
int n;
void scc(vector<vector<int>> &adj, vector<vector<int>> &components, vector<vector<int>> &adj_cond){
    components.clear(), adj_cond.clear(); st.clear();
    t_in.assign(n,-1);
    t_low.assign(n,-1);
    roots.assign(n,-1);

    // cout << "vou entrar na dfs" << endl; 

    for(int v=0;v<n;v++){
        if(t_in[v] == -1) dfs(v,adj, components);
    }

    // cout << "sai da dfs" << endl;
    adj_cond.assign(n,{});
    for(int v=0;v<n;v++){
        for(auto u: adj[v]){
            if(roots[u] != roots[v]) adj_cond[roots[v]].push_back(roots[u]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int m; cin >> n >> m; 
    vector<vector<int>> adj(n, vector<int>()), components, adj_cond;
    val.resize(n); visited.resize(n); sum_comp.resize(n, 0);

    vector<int> order; 
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b; 
        a--; b--; 
        adj[a].push_back(b);
    } 
    // cout << "vou chamar a scc" << endl;
    scc(adj,components, adj_cond);
    for(int i=0;i<n;i++){
        if(roots[i] == i && !visited[i]) top_order(i, adj_cond, order); // ordenando topologicamente pelas componentes fortemente conexas 
    }
    // reverse(order.begin(), order.end());
    vector<int> dp(n,0);
    // // isso aqui vai começar pelo final da ordenação topológica de order
    int max_dist = LLONG_MIN;
    for(auto v: order){
        int resp = 0;
        for(auto u: adj_cond[v]){
            resp = max(resp, dp[u]);
        }
        dp[v] = resp + sum_comp[v];
        max_dist = max(max_dist, dp[v]);
    }

    cout << max_dist << endl;
    
    return 0;
}