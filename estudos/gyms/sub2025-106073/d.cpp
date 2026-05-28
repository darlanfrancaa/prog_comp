#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/gym/106073/problem/D

const int BITS = 21; 
const int MAX_MASK = 1 << BITS;
int dp[MAX_MASK];
pair<int,int> arestas[BITS];
int aresta_id[7][7];

bool visited[7];
vector<int> adj[7];

void dfs(int u){
    visited[u] = true;
    for(auto node: adj[u]){
        if(!visited[node]) dfs(node);
    }
}

void precompute(){
    int id = 0; 
    for(int i=1;i<=6;i++){
        for(int j=i; j<=6;j++){
            aresta_id[i][j] = aresta_id[j][i] = id;
            arestas[id] = {i,j};
            id++;
        }
    }

    for(int mask=1; mask< MAX_MASK;mask++){
        int deg[7] = {0};
        for(int i=1;i<=6;i++){
            adj[i].clear(); 
            visited[i] = false;
        }

        int begin = -1; 

        for(int i=0;i<BITS;i++){
            if(mask & (1 << i)){
                int u = arestas[i].first; 
                int v = arestas[i].second;

                deg[u]++; deg[v]++; 
                adj[u].push_back(v); adj[v].push_back(u);
                if(begin == -1) begin = u;
            }
        }

        int impares = 0; 
        for(int i=1;i<=6;i++){
            if(deg[i] % 2 == 1) impares++;
        }
        if(impares != 0 && impares != 2) continue;
        dfs(begin);
        bool conexo = true;
        for(int i=1;i<=6;i++){
            if(deg[i] > 0 && !visited[i]){
                conexo = false; 
                break;
            }
        }
        if(conexo) dp[mask] = 1;
    }

    for(int i=0;i<BITS;i++){
        for(int mask = 0; mask < MAX_MASK; mask++){
            if(mask & (1 << i)){
                dp[mask] += dp[mask ^ (1 << i)];
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    precompute();
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int mask = 0; 
        for(int i=0;i<n;i++){
            int u,v; cin >> u >> v;
            mask |= (1 << aresta_id[u][v]);
        }

        cout << dp[mask] << "\n";
    }
    return 0;
}