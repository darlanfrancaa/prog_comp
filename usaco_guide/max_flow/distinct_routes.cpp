#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1711

const int MAXN = 510; 
const int MAXM = 1010;

vector<int> adj[MAXN];
int cap[MAXN][MAXN];
int orig_cap[MAXN][MAXN];

int n,m;

int bfs(int s, int t, vector<int> &parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2; 
    queue<pair<int,int>> q; 
    q.push({s,LLONG_MAX});
    while(!q.empty()){
        auto [curr,flow] = q.front(); q.pop();
        for(int node: adj[curr]){
            if(parent[node] == -1 && cap[curr][node]){
                parent[node] = curr; 
                int new_flow = min(flow, cap[curr][node]);
                if(node == t) return new_flow; 
                q.push({node, new_flow});
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0;
    vector<int> parent(n);
    int new_flow; 
    // int contador = 1; 
    while(new_flow = bfs(s,t,parent)){
        // printf("entrei %lld vezes\n", contador++);
        stack<int> pilha;
        flow += new_flow; 
        int curr = t; 
        while(curr != s){
            pilha.push(curr);
            int prev = parent[curr];
            cap[prev][curr] -= new_flow;
            cap[curr][prev] += new_flow;
            curr = prev;
        }
        pilha.push(s);
    }
    return flow;
}

void dfs(int s, int t, int v, vector<int> &path){
    path.push_back(v);
    if(v == t) return;
    for(auto node: adj[v]){
        if(orig_cap[v][node] == 1 && cap[v][node] == 0){
            cap[v][node] = 1; 
            dfs(s,t,node, path);
            return;
        }
    }
}


signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; 
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v; 
        u--;v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += 1;
        orig_cap[u][v] += 1;
    }

    int fluxo_max = max_flow(0,n-1);
    cout << fluxo_max << '\n';
    for(int i=0;i<fluxo_max;i++){
        vector<int> caminho; 
        dfs(0,n-1,0,caminho);
        cout << caminho.size() << '\n';
        for(int i=0;i<caminho.size();i++){
            cout << caminho[i]+1 << ' ';
        }
        cout << "\n";

    }

    
    return 0;
}