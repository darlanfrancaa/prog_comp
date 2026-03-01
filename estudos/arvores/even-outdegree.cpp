#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int N = 1e5+10;
const int M = 2e5+10;

// problem link: https://cses.fi/problemset/task/2179

struct Edge{ 
    int idx, a , b;

    bool operator<(const Edge &aresta) const{
        return idx < aresta.idx;
    }
};
vector<pii> adj[N]; // vai salvar um par {idx,b} significando que a aponta pra b e o indice da aresta é idx
bool paridade[N], edge_used[M];
bool mst[M];
vector<Edge> ans;
bool visitado[N], vis[N];
void dfs_mst(int v){
    visitado[v] = true;
    for(auto [node, idx]: adj[v]){
        if(edge_used[idx]) continue;
        edge_used[idx] = true;
        if(!visitado[node]){
            mst[idx] = true;
            dfs_mst(node);
        } else {
            mst[idx] = false;
            ans.push_back({idx,v, node}); // coloco a aresta orientada na resposta
            paridade[v] ^= 1; // troco a paridade do pai
        }
    }
}

void dfs(int v){
    vis[v] = true;
    for(auto [node, idx]: adj[v]){
        if(vis[node]) continue;
        if(!mst[idx]) continue;
        dfs(node); // então estamos agora apenas em arestas da mst e para baixo
        if(paridade[node]) { // então eu tenho que colocar a aresta saindo de node
            ans.push_back({idx,node,v});
            paridade[node] ^= 1;
        } else {
            ans.push_back({idx,v,node});
            paridade[v] ^= 1;
        }
    }
}


signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;   
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b; 
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }

    for(int i=1;i<=n;i++){
        if(!visitado[i]){
            dfs_mst(i);
            dfs(i);

            if(paridade[i]){
                cout << "IMPOSSIBLE" << endl; 
                return 0;
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(int i=0;i<m;i++){
        cout << ans[i].a << " " << ans[i].b << endl;
    }
    return 0;
}