#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
struct DSU{ 
    vector<int> parent,sz;

    DSU(int n){
        parent.resize(n);
        sz.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    int tam(int i){ 
        return sz[find(i)];
    }

    bool merge(int x, int y){
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (sz[rx] < sz[ry]) swap(rx,ry); 
        parent[ry] = rx;
        sz[rx] += sz[ry];
        return true; 
    }


};
struct Aresta{ 
    int a,b, peso; 
};

bool cmp_aresta(Aresta &a, Aresta &b){  
    return a.peso > b.peso;
}

bool cmp_queries(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
	return a.second.first > b.second.first;
}

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    vector<Aresta> arestas(n - 1);
    for(int i=0;i<n-1;i++){
        int a,b,peso; cin >> a >> b >> peso; 
        a--, b--; 
        arestas[i] = {a,b,peso};
    }
    vector<pair<int,pair<int,int>>> queries(q);
    for(int i=0;i<q;i++){
        int k,v; cin >> k >> v; 
        v--; 
        queries[i] = {i,{k,v}};
    }
    sort(queries.begin(), queries.end(), cmp_queries);
    sort(arestas.begin(), arestas.end(), cmp_aresta);

    DSU dsu(n); 
    vector<int> sol(q);
    int idx = 0; 
    for(auto query: queries){ 
        auto [k_atual,v] = query.second;
        while(idx < n-1 && arestas[idx].peso >= k_atual){
            dsu.merge(arestas[idx].a, arestas[idx].b);
            idx++;
        }
        sol[query.first] = dsu.tam(v) - 1;
    }
    for(auto s: sol ){
        cout << s << endl; 
    }
    return 0;
    
}