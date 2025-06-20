#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
vector<int> visitado;
vector<int> destinos;
vector<int> ans;
queue<int> caminho; 


void dfs(vector<int> &destinos, vector<int> &ans, queue<int> &caminho, int comeco, int &passos){
    caminho.push(comeco);
    if(visitado[comeco]){
        passos += ans[comeco];
        return;
    }
    visitado[comeco] = true;
    passos++;
    int proximo = destinos[comeco];
    dfs(destinos, ans, caminho, proximo, passos);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    destinos.resize(n);
    ans.assign(n,0);
    visitado.resize(n);
    for(int i=0;i<n;i++){
        cin >> destinos[i];
        destinos[i]--;
    }
    for(int i=0;i<n;i++){
        if(!visitado[i]){
            int passos = 0; 
            dfs(destinos, ans, caminho, i, passos);
            int desce = 1;
            while(!caminho.empty()){
                if(caminho.front() == caminho.back()) desce = 0;
                ans[caminho.front()] = passos;
                passos -= desce;
                caminho.pop();
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}