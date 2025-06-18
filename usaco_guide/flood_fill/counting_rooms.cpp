#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1010;
int n, m;
char matriz[MAXN][MAXN];

void dfs(int i, int j, int componente, vector<vector<int>> &visitado){
    if(i<0 || i>= n || j<0 || j>= m) return;
    if(visitado[i][j] != - 1 || matriz[i][j] == '#') return;
    visitado[i][j] = componente;
    dfs(i,j+1,componente,visitado);
    dfs(i,j-1,componente,visitado);
    dfs(i+1,j,componente,visitado);
    dfs(i-1,j,componente,visitado);
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matriz[i][j];
        }
    }
    int componente = 0; 
    vector<vector<int>> visitado (n,vector<int> (m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visitado[i][j] == -1 && matriz[i][j] == '.') {
                componente++;
                dfs(i,j,componente,visitado);
            }
        }
    }
    cout << componente << '\n';
    return 0;
}