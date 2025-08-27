#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct Edges {
    int a,b, w; 
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,x; cin >> n >> m >> x; 
    vector<vector<int>> adj(n, vector<int>());
    vector<Edges> arestas;
    for(int i=0;i<m;i++){
        int a, b, w; cin >> a >> b >> w; 
        a--;b--; 
        arestas.push_back({a,b,w});
    }
    vector<int> dist(n, INT_MAX);
    dist[x] = 0;
    for(int i=0;i<n;i++){
        for(auto e: arestas){
            auto [a,b,w] = e;
            dist[b] = min(dist[b], dist[b]+a);
        }
    }
    return 0;
}