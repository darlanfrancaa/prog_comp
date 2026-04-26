#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

vector<int> t_in, t_low, roots, st;
int timer = 0; 
vector<int> sum_comp;
vector<bool> visited;

vector<vector<pii>> adj, adj_cond; 
vector<vector<int>> components;


int calc_total(int w) {
    int l = 0, r = 20000, k = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(mid * (mid + 1) / 2 <= w) {
            k = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return (k + 1) * w - k * (k + 1) * (k + 2) / 6;
}

void top_order(int v, vector<vector<pii>> &adj, vector<int> &order){
    visited[v] = true;
    for(auto edge: adj[v]){
        int u = edge.first;
        if(!visited[u]) top_order(u, adj, order);
    }
    order.push_back(v);
}

void dfs(int v, vector<vector<pii>> &adj, vector<vector<int>> &components){
    t_in[v] = t_low[v] = timer++; 
    st.push_back(v);
    
    for(auto edge: adj[v]){
        int u = edge.first;
        if(t_in[u] == -1){
            dfs(u, adj, components);
            t_low[v] = min(t_low[v], t_low[u]);
        } else if(roots[u] == -1){
            t_low[v] = min(t_low[v], t_in[u]);
        }
    }

    if(t_in[v] == t_low[v]){
        vector<int> component;
        while(true){
            int u = st.back(); st.pop_back();
            roots[u] = v; 
            component.push_back(u);
            if(u == v) break;
        }
        components.push_back(component);
    }
}

int n;
void scc(vector<vector<pii>> &adj, vector<vector<int>> &components, vector<vector<pii>> &adj_cond){
    components.clear(), adj_cond.clear(); st.clear();
    t_in.assign(n, -1);
    t_low.assign(n, -1);
    roots.assign(n, -1);

    for(int v=0;v<n;v++){
        if(t_in[v] == -1) dfs(v, adj, components);
    }

    adj_cond.assign(n, {});
    sum_comp.assign(n, 0); 

    for(int v=0;v<n;v++){
        for(auto edge: adj[v]){
            int u = edge.first;
            int w = edge.second;
            
            if(roots[v] == roots[u]){
                sum_comp[roots[v]] += calc_total(w);
            } else {
                adj_cond[roots[v]].push_back({roots[u], w});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int m; cin >> n >> m; 
    
    adj.assign(n, {});
    visited.assign(n, false); 

    for(int i=0;i<m;i++){
        int a, b, w; cin >> a >> b >> w; 
        a--; b--; 
        adj[a].push_back({b, w});
    } 
    
    int s; cin >> s; 
    s--; 

    scc(adj, components, adj_cond);
    
    vector<int> order; 
    for(int i=0;i<n;i++){
        if(roots[i] == i && !visited[i]) top_order(i, adj_cond, order); 
    }
    
    vector<int> dp(n, 0);
    for(auto v: order){
        int resp = 0;
        for(auto edge: adj_cond[v]){
            int u = edge.first;
            int w = edge.second;
            resp = max(resp, dp[u] + w);
        }
        dp[v] = resp + sum_comp[v];
    }

    cout << dp[roots[s]] << "\n";
    
    return 0;
}