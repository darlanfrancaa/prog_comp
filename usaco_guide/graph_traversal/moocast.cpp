#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
int n;

struct Cow {
    int p, x,y, idx;
};

struct a_reach_b {
    bool operator()(const Cow& a, const Cow& b){
        long long dx = (long long) b.x - a.x;
        long long dy = (long long) b.y - a.y;
        return dx*dx + dy*dy <=(long long) a.p * a.p;
    }
};


vector<Cow> vacas;
vector<vector<int>> grafo;
vector<int> visitado;

// void dfs(int x){
//     if(visitado[x]) return; 
//     visitado[x] = true; 
//     for(auto v: grafo[x]) dfs(v);
// }

int bfs(int x){
    int contador = 1;
    queue<int> q; 
    q.push(x);
    visitado[x] = true;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto u: grafo[v]){
            if(visitado[u]) continue;
            visitado[u] = true;
            contador++;
            q.push(u);
        }
    }
    return contador;
}


int main() {
    // freopen("moocast.in", "r", stdin);
    // freopen("moocast.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n; 
    vacas.resize(n); grafo.resize(n); visitado.resize(n);
    for(int i=0;i<n;i++){
        int x,y,p; cin >> x >> y >> p; 
        vacas[i].x = x; vacas[i].y = y; vacas[i].p = p; vacas[i].idx = i;
    }
    a_reach_b comparador;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!= j && comparador(vacas[i],vacas[j])){
                grafo[i].push_back(j);
            }
        }
    }
    int maximo = INT_MIN;
    for(int i=0;i<n;i++){
        fill(visitado.begin(),visitado.end(),false);
        maximo = max( maximo , bfs(i));
    }
    cout << maximo;

    return 0;
}