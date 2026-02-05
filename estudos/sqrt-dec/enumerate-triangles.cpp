#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 998244353;

// problem link: https://judge.yosupo.jp/problem/enumerate_triangles

bool comp(pii a, pii b){
    return a.second > b.second;
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m; 
    vector<int>  val(n); 
    vector<int> deg(n);
    vector<pii> arestas;

    // eu quero ordenar os vértices pelos graus deles e depois eu quero 
    for(int i=0;i<n;i++) cin >> val[i];
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b; 
        deg[a]++; deg[b]++;
        arestas.push_back({a,b});
    }
    // sort(vertices.begin(), vertices.end(),comp); 
    // for(int i=0; i < n; i++){
    //     printf("o vértice %lld tem %lld arestas saindo dele \n", vertices[i].first, vertices[i].second);
    // }
    vector<int> adj[n]; 
    for(int i=0;i<m;i++){
        auto [u,v] = arestas[i];
        bool maior = false; 

        if(deg[u] < deg[v]) maior = true;
        else if(deg[u] == deg[v] && u < v) maior = true;
        if(maior) adj[u].push_back(v); 
        else adj[v].push_back(u);
    }
    int ans = 0;
    vector<bool> used(n);
    for(int v=0;v<n;v++){
        for(int node: adj[v]) used[node] = true;  
        for(int node : adj[v]){
            for(int node1: adj[node]){
                if(used[node1]) {
                    ans = (ans + ((((val[v] * val[node]) % MOD) * val[node1]) % MOD)) % MOD;
                }
            }
        }
        for(int node: adj[v]) used[node] = false;
    }
    cout << ans << "\n";
    return 0;
}