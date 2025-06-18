#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;


int n, m; 
vector<vector<int>> grafo;
vector<vector<int>> grafo_2;
vector<int> visitado;
vector<int> visitado_2;
 
void bfs(int x, const vector<vector<int>>& a, vector<int>& visited){
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int v = q.front();q.pop();
        for(auto u: a[v]){
            if(visited[u]) continue;
            q.push(u);
            visited[u] = true;
        }
    }
}


int main() {
    cin >> n >> m;
    grafo.resize(n);
    grafo_2.resize(n);
    visitado.resize(n);
    visitado_2.resize(n);
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b;
        a--;b--;
        grafo[a].push_back(b);
        grafo_2[b].push_back(a);
    }
    bfs(0,grafo,visitado);
    bfs(0,grafo_2,visitado_2);
    for(int i=1;i<n;i++){
        if(!visitado[i]) {
            cout << "NO" << endl << 1 << " " << i+1 ;
            return 0;
        } else if(!visitado_2[i]) {
            cout << "NO" << endl << i+1 << " " << 1;
            return 0;
        }
    }
    cout << "YES";
}