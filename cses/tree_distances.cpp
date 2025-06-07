#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

vector<vector<int>> adj; 
vector<int> down1;
vector<int> down2;
vector<int> caminho1;
vector<int> cima;

//primeiro faremos uma dfs para calcular os maiores caminhos para baixo(ou seja down1,down2), enraizando a raiz num vertice fixo.
void dfs_down(int node, int pai){
    for(int v: adj[node]){
        if(v == pai) continue;
        dfs_down(v, node);
        if(down1[v] + 1 > down1[node]){
            down2[node] = down1[node];
            down1[node] = down1[v] + 1;
            caminho1[node] = v;
        } else if( down1[v] + 1 > down2[node]){
            down2[node] = down1[v] + 1;
        }
    }
}

void dfs_up(int node, int pai){
    for(int v: adj[node]){
        if(v == pai) continue;
        if(v == caminho1[node]) {
            cima[v] = 1 + max(cima[node],down2[node]);
        } else {
            cima[v] = 1 + max(cima[node],down1[node]);
        }
        dfs_up(v,node);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    adj.resize(n );
    down1.resize(n,0);
    down2.resize(n,0);
    caminho1.resize(n,0);
    cima.resize(n, 0);
    for(int i=0;i<n-1;i++){
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_down(0,-1);
    dfs_up(0,-1);
    for(int i=0;i<n;i++){
        cout << max(down1[i], cima[i]) << " ";
    }
    cout << endl;
    return 0;
}