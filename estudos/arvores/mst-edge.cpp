#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link : 

const int N = 2e5+10;
const int LOG = 20;

struct Edge { 
    int v; int peso;
};

struct ArestaGrafo { 
    int u, v, peso, id; 

    bool operator<(const ArestaGrafo& other) const{
        return peso < other.peso;
    }
};

bool is_mst[N]; 

struct DSU { 
    vector<int> parent, sz;
    DSU(int n){
        parent.resize(n+1);
        sz.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i] = i;
    }

    int find(int i){
        if(parent[i] == i) return i; 
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j){
        int ri = find(i);
        int rj = find(j);
        if(ri != rj) {
            if(sz[ri] < sz[rj]) swap(ri,rj); 
            parent[rj] = ri;               
            sz[ri] += sz[rj];                
        }
    }
};

pair<vector<ArestaGrafo>, int> kruskal(int n, vector<ArestaGrafo>& arestas){
    sort(arestas.begin(), arestas.end());
    DSU dsu(n);
    vector<ArestaGrafo> ret;
    int mst_peso = 0;

    for(const auto &edge: arestas){
        if(dsu.find(edge.u) != dsu.find(edge.v)){
            dsu.unite(edge.u, edge.v);
            mst_peso += edge.peso;
            ret.push_back(edge);
            
            is_mst[edge.id] = true; 
        }
    }

    return {ret, mst_peso};
}

int n, m; 
int depth[N];
int up[N][LOG], st[N][LOG]; 

vector<Edge> adj[N];
vector<ArestaGrafo> queries;
vector<ArestaGrafo> arestas;

void dfs(int u, int p, int d, int peso){
    depth[u] = d;
    up[u][0] = p;
    st[u][0] = peso;

    for(int i = 1;i < LOG;i++){
        if(up[u][i-1] != 0)
            up[u][i] = up[up[u][i-1]][i-1];
        else up[u][i] = 0;
        
        if(st[u][i-1] != 0)
            st[u][i] = max(st[u][i-1], st[up[u][i-1]][i-1]);
        else 
            st[u][i] = 0;
    }

    for(auto &[node, peso_pai]: adj[u]){
        if(node != p){
            dfs(node, u, d+1, peso_pai);
        }   
    }
}

int sobe_k(int v, int k){
    for(int i= LOG -1;i>=0;i--){
        if(k & (1 << i)){
            v = up[v][i];
            if(v == 0) return 0;
        }
    }
    return v;
}

int get_lca(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    int diff = depth[u] - depth[v];
    u = sobe_k(u,diff);
    if(u == v) return u;
    for(int i = LOG -1; i>=0;i--){
        if (up[u][i] != up[v][i] && up[v][i] != 0) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

int get_max(int a, int b){
    int lca = get_lca(a,b);
    int maximo1 = 0, maximo2 = 0;
    int dist1 = depth[a] - depth[lca];
    int dist2 = depth[b] - depth[lca];
    
    for(int i=LOG-1;i>=0;i--){
        if(dist1 & (1 << i)){
            maximo1 = max(maximo1, st[a][i]);
            a = up[a][i];
        }
    } 

    for(int i=LOG-1;i>=0;i--){
        if(dist2 & (1 << i)){
            maximo2 = max(maximo2, st[b][i]);
            b = up[b][i];
        }
    } 

    return max(maximo1,maximo2);
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m; 
    for(int i=0;i<m;i++){
        int a, b, peso; cin >> a >> b >> peso; 
        ArestaGrafo query = {a, b, peso, i}; 
        queries.push_back(query);
    }

    arestas = queries;

    auto [vetorArestasMst, mst_peso] = kruskal(n, queries); 
    
    for(auto &[u,v,peso,id]: vetorArestasMst){
        adj[u].push_back({v,peso});
        adj[v].push_back({u,peso});
    } 
    
    dfs(1,0,0,0);
    
    for(auto edge: arestas){
        auto [a, b, peso, id] = edge;
        
        if(is_mst[id]){
            cout << mst_peso << "\n";
            continue;
        }
        
        int maximo = get_max(a,b);
        int ret = mst_peso + peso - maximo;
        
        cout << ret << "\n";
    }
    
    return 0;
}