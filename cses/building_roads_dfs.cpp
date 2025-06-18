#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
int n, m; 
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int s){
    if(visited[s]) return; 
    visited[s] = true;
    for(auto v: adj[s]) dfs(v);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    adj.resize(n);
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b; 
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    visited.resize(n);
    vector<int> componentes; // cada entrada vai armazenar o "pai" de uma nova componente
    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        componentes.push_back(i);
        dfs(i);
    }
    cout << componentes.size() - 1 << endl;
    for(int i=0; i < componentes.size()- 1 ; i++){
        cout << componentes[i] + 1 << " " << componentes[i+1] + 1 << endl;
    }
    return 0;
}