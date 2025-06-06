#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    vector<char> fazendas(n,0);
    for(auto &f: fazendas){
        cin >> f; 
    }
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int comp; 
    vector<int> componente(n,-1);
    // definimos aqui como componente todo mundo que so da pra chegar passando um tipo fixo.
    // ou seja, se estao em componentes diferentes eh sempre possivel escolher um tipo que voce queira no caminho
    // caso contrario só eh possivel se o tipo de leite for o mesmo do desejado
    for(int i=0;i<n;i++){
        if(componente[i] != -1) continue;
        queue<int> fila;
        char leite = fazendas[i];
        fila.push(i);
        while(!fila.empty()){
            int v = fila.front(); fila.pop();
            componente[v] = comp;
            for(auto k: adj[v]){
                if(fazendas[k] == leite && componente[k] == -1) fila.push(k);
            }
        }   
        comp++;
    }
    for(int i=0;i<q;i++){
        int a, b; 
        char milk; cin >> a >> b >> milk;
        a--; b --;
        if(componente[a] == componente[b]){
            cout << (fazendas[a] == milk);
        } else {
            cout << 1;
        }
    }


    return 0;
}