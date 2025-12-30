#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1695
const int MAXN = 510;
int n,m; 
vector<int> adj[MAXN];
int cap[MAXN][MAXN];
int orig_cap[MAXN][MAXN]; 

// essa função vai encontrar um fluxo que passa pelo número mínimo de arestas entre s e t e salva em parent os pais de cada um no caminho

int bfs(int s, int t, vector<int> &parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pii> q; 
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

    while(new_flow = bfs(s,t,parent)){
        // printf("encontrei um fluxo de s pra t com custo %lld, segue caminho encontrado\n", new_flow);
        flow += new_flow;
        int curr = t; 
        while(curr != s){
            // printf("%lld <- ", curr);
            int prev = parent[curr];
            cap[prev][curr] -= new_flow;
            cap[curr][prev] += new_flow;
            curr = prev;
        }
        // cout << "\n";
    }
    return flow;
}

// agora depois de fazer o ford-fulkerson eu gostaria de, no grafo de orig_cap, saber até quem eu posso chegar

bool visited[MAXN];

void dfs(int node, vector<bool> &esq){
    if(visited[node]) return;
    visited[node] = true;
    esq[node] = true;
    for(int next: adj[node]){
        if(visited[next] == false && cap[node][next] > 0){ // se eu já não passei por aqui e se a aresta existe de modo direcionado então eu chamo para o próximo no grafo restante
            dfs(next,esq);
        }
    }
}



signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v; 
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += 1;
        cap[v][u] += 1;
        orig_cap[u][v] += 1;
        orig_cap[v][u] += 1;
    }

    int cham = max_flow(0,n-1);
    // printf("o fluxo máximo foi %lld\n", cham);
    vector<bool> esq(n), dir(n, false); 
    dfs(0,esq);
    // for(int i=0;i<esq.size();i++){
    //     cout << esq[i] << " ";
    // }
    // cout << "\n";
    for(int i=0;i<n;i++){
        if(!esq[i]) dir[i] = 1;
    }
    // for(int i=0;i<esq.size();i++){
    //     cout << dir[i] << " ";
    // }
    // cout << "\n";
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(esq[i] && dir[j] && orig_cap[i][j] > 0) {
                count++;
            }
        }
    }

    cout << count << "\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(esq[i] && dir[j] && orig_cap[i][j] > 0) {
                cout << i+1 << " " << j+1 << '\n';
            }
        }
    }
    
    return 0;
}