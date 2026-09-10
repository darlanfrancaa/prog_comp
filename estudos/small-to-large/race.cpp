#include <bits/stdc++.h>
#include "race.h"
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://oj.uz/problem/view/IOI11_race

const int MAXN = 2e5+1;
vector<pii> adj[MAXN];
map<int,int> info[MAXN];
int dist[MAXN], sum[MAXN];
int N, K; 
int ret;

void dfs(int u, int p, int val, int h){ // estou definindo tanto a distância quando a profundidade de um vértice v até a altura
    info[u][val] = h;
    sum[u] = val; 
    dist[u] = h; 
    for(auto [node, aresta]: adj[u]){
        if(node == p) continue; 
        dfs(node, u, val + aresta, h+1);
    }
}

void small_to_large(int u, int p){
    int valor = K + 2 * sum[u]; // quero saber se tem dois caras que somam esse valor na subárvore
    for(auto [filho, distancia]: adj[u]){
        if(filho == p) continue; 
        small_to_large(filho, u);
        if(info[filho].size() > info[u].size()) {
            swap(info[filho], info[u]);
        }
        for(auto [dist1, qtd1]: info[filho]){
            if(info[u].find(valor - dist1) != info[u].end()) { // procuro se ao colocar o filho dentro do pai tem algum valor que soma dist
                ret = min(ret, info[u][valor-dist1] + qtd1 - 2 * dist[u]);
            }
        }
        for(auto [dist1, qtd1]: info[filho]){
            if(info[u].find(dist1) == info[u].end()){
                info[u][dist1] = qtd1;
            } else {
                info[u][dist1] = min(info[u][dist1], qtd1);
            }
        }
        info[filho].clear();
    }
}

int32_t best_path(int32_t n, int32_t k, int32_t edges[][2], int32_t L[]){
    N = n; 
    K = k; 
    ret = LLONG_MAX;
    for(int i=0;i<n-1;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back({v, L[i]});
        adj[v].push_back({u, L[i]});
    }
    dfs(0,-1,0,0);
    small_to_large(0,-1);
    if(ret == LLONG_MAX) {
        ret = -1; 
    } 
    return ret;
}
 