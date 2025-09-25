#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
int n; 
vector<vector<char>> tab; 
vector<vector<int>> visitado;

pair<int,int> next(char op, int i, int j){
    if(op == '>') j++;
    else if(op == '<') j--;
    else if(op == 'A') i--;
    else if(op == 'V') i++; 
    return {i,j};
}

bool dentro(int i, int j){
    return 0 <= i && i < n && 0 <=j && j < n;
}

int dfs(int i, int j){
    if(!dentro(i,j)) return 0; // vamos atribuir o valor de 0 a todos que sairem
    if(visitado[i][j] == 0) return 0; // quer dizer que esse cara aqui vai sair na frente
    if(visitado[i][j] == 1) return 1; // quer dizer que esse cara aqui não saiu e eu encontrei um ciclo
    visitado[i][j] = 1; // quer dizer que eu já passei por esse vértice apenas
    auto [i1,j1] = next(tab[i][j], i, j);
    return visitado[i][j] = dfs(i1,j1);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n; 
    tab.resize(n, vector<char> (n));
    visitado.resize(n,vector<int> (n,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> tab[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visitado[i][j] == -1){
                dfs(i,j);
            }
        }
    }
    int contador = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visitado[i][j] == 1) contador++;
        }
    }
    cout << contador << "\n";
    return 0;
}