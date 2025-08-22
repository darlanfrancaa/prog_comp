#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
using pii = pair<int,int>; 

struct Aresta{
    int a , b, dist;
};

int dist(pii &a, pii&b){
    int dx = a.first - b.first; 
    int dy = a.second - b.second;
    return dx * dx + dy * dy;
}

bool cmp_arestas(Aresta &a, Aresta &b){
    return a.dist <  b.dist;
}

struct DSU{
    vector<int> parent, sz; 
    int componentes; 
    DSU(int n){
        parent.resize(n);
        sz.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        componentes = n;
    }

    int find(int i){
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool merge(int a, int b){
        int ra = find(a), rb = find(b);
        if(ra == rb ) return false; 
        if(sz[ra] < sz[rb]) swap(ra,rb);
        parent[rb] = ra; 
        sz[ra] += sz[rb]; 
        componentes--; 
        return true; 
    }

    int comp(){
        return componentes;
    }
};


int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<pii> vertices(n);
    for(auto &v:vertices) cin >> v.first >> v.second;
    vector<Aresta> arestas;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int distancia = dist(vertices[i], vertices[j]);
            arestas.push_back({i,j,distancia});
        }
    }
    sort(arestas.begin(), arestas.end(), cmp_arestas);

    DSU dsu(n);
    int last_dist = 0; 
    for(auto a: arestas){
        if(dsu.merge(a.a, a.b)){
            last_dist = a.dist;
            if(dsu.comp() == 1) break;
        }
    }
    cout << last_dist << endl; 
    return 0;
}