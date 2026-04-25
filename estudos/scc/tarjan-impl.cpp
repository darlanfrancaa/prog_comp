#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

vector<int> st;
vector<int> roots; 

int timer; 
vector<int> t_in; 
vector<int> t_low; 

void dfs(int v, vector<vector<int>> const &adj, vector<vector<int>> &components){
    t_low[v] = t_in[v] = timer++; 
    st.push_back(v);

    for(auto u: adj[v]){
        if(t_in[u] == -1){
            dfs(v,adj,components);
            t_low[v] = min(t_low[v], t_low[u]);
        } else if (roots[u] == -1){
            t_low[v] = min(t_low[v], t_in[u]);
        }
    }

    if(t_low[v] == t_in[v]){
        components.push_back({v});
        while(true){
            int u = st.back(); st.pop_back(); 
            roots[u] = v;
            if(u == v){
                break;
            }
            components.back().push_back(u);
        }
    }
}

void scc(vector<vector<int>> const &adj, vector<vector<int>> &components, vector<vector<int>> &adj_cond){
    components.clear(); 
    adj_cond.clear(); 

    int n = adj.size(); 
    st.clear(); 
    timer = 0; 
    t_in.assign(n,-1); 
    t_low.assign(n,-1);

    for(int v=0;v<n;v++){
        if(t_in[v] == -1){
            dfs(v,components, adj_cond);
        }
    }

    adj_cond.assign(n,{});
    for(int v=0; v<n;v++){
        for(auto u: adj[v]){
            if(roots[u] != roots[v]) adj_cond[roots[v]].push_back(roots[u]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}