#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
vector<int> funcao; 
vector<bool> visitado;
queue<int> caminho;

void dfs(int comeco){
    caminho.push(comeco);
    if(visitado[comeco]){
        return;
    } else {
        visitado[comeco] = true;
        dfs(funcao[comeco]);
    }
}

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    funcao.resize(n);visitado.resize(n);
    for(int i=0;i<n;i++){
        int a; cin >> a; a--;
        funcao[i] = a;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(!visitado[i]){
            while(!caminho.empty()) caminho.pop();
            dfs(i);
            while(caminho.back() != caminho.front()) caminho.pop();
            ans += caminho.size() - 1;
        } 
    }
    cout << ans << endl; 
    return 0;
}