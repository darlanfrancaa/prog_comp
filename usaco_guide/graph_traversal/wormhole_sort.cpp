#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct Aresta{
    int a,b,peso;
};
vector<Aresta> arestas;
int n,m; 
vector<int> vacas;
vector<int> componente_g;
vector<vector<Aresta>> grafo;


void bfs(int peso, vector<int> &componente){
    fill(componente.begin(),componente.end(),-1);
    int nmr_componente = 0;
    for(int i=0;i<n;i++){
        if(componente[i]!=-1) continue;
        nmr_componente++;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int v = q.front(); q.pop();
            componente[v] = nmr_componente;
            for(auto aresta: grafo[v]){
                if(aresta.peso >= peso && componente[aresta.b] == -1) q.push(aresta.b);
            }
        }
    }
}

bool da_certo(int peso, vector<int> &componente){
    fill(componente.begin(),componente.end(), -1);
    bfs(peso,componente);
    for(int i=0;i<n;i++){
        if(!(componente[vacas[i]] == componente[i])) return false;
    }
    return true;
}


int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vacas.resize(n);
    arestas.resize(m);
    componente_g.resize(n);
    grafo.resize(n);
    for(auto &i:vacas) {
        cin >> i;
        i--;
    }
    int max_peso = 0;
    for(int i=0;i<m;i++) {
        int a,b,p; cin >> a >> b >> p;
        max_peso = max(p, max_peso);
        a--;b--;
        arestas[i] = {a,b,p};
        grafo[a].push_back({a,b,p});
        grafo[b].push_back({b,a,p});
    }
     if(is_sorted(vacas.begin(),vacas.end())){
        cout << -1 << endl; 
        return 0;
    }
    int left = 1, right = max_peso;
    while(left < right){
        int mid = left + (right - left +1 )/2;
        if(da_certo(mid,componente_g)) left = mid;
        else right = mid-1;
    }
    cout << left << endl;
    return 0;
}