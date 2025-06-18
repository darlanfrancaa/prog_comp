#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct Ponto {
    int x, y, idx;
};

int n,m;
vector<Ponto> cows;
vector< vector<int>> grafo;
vector<bool> visitado;


int bfs(int x){
    int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
    queue<int> q; 
    q.push(x);
    visitado[x] = true;
    while(!q.empty()){
        int v = q.front(); q.pop();
        minx = min(minx,cows[v].x);
        miny = min(miny,cows[v].y);
        maxx = max(maxx,cows[v].x);
        maxy = max(maxy,cows[v].y);
        for(auto u: grafo[v]){
            if(visitado[u]) continue;
            visitado[u] = true;
            q.push(u);
        }
    }
    int perimetro = 2 * (maxx-minx + maxy - miny);
    return perimetro;
}



int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
	cin >> n >> m;
    cows.resize(n);
    grafo.resize(n);
    visitado.resize(n);
    fill(visitado.begin(),visitado.end(),false);
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        cows[i] = {a,b,i};
    }
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b;
        grafo[--a].push_back(--b);
        grafo[b].push_back(a);
    }
    int cor = 1;
    int minimo = INT_MAX;
    for(int i=0;i<n;i++){
        if(!visitado[i]) minimo = min(minimo, bfs(i));
    }
    cout << minimo << endl;
    


}