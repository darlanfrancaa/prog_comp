#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

const int MAXN = 3e5; 

int timer; 
int scc; 
int id[MAXN];
int low[MAXN];
vector<int> adj[MAXN];
vector<int> two_edge_comp[MAXN];
stack<int> st;

void dfs(int v, int p = -1){
    id[v] = low[v] = timer++;
    st.push(v);
    bool multiple_edges = false; 

    for(int child: adj[v]){
        if(child == p && !multiple_edges){
            multiple_edges = true; 
            continue;
        }
        if(!id[child]){
            dfs(child, v);
            low[v] = min(low[v], low[child]);
        } else { 
            low[v] = min(low[v], id[child]);
        }
    }

    if(low[v] == id[v]){
        while(st.top() != v){
            two_edge_comp[scc].push_back(st.top());
            st.pop();
        }
        two_edge_comp[scc++].push_back(st.top());
        st.pop(); 
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}