#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct DSU {
    vector<int> pai;
    vector<int> sz;
    int componentes;
    int maximo;

    DSU(int n){
        pai.resize(n);
        sz.resize(n,1);
        for(int i=0;i<n;i++){
            pai[i] = i;
        }
        componentes = n;
        maximo = (n>0) ? 1 : 0;
    }

    int find(int i){
        if(pai[i] == i){
            return i;
        }
        return pai[i] = find(pai[i]);
    }

    bool merge(int a, int b){
        int raiz1 = find(a);
        int raiz2 = find(b); 
        if(raiz1 == raiz2) return false; 
        if(sz[raiz1] < sz[raiz2]) swap(raiz1, raiz2);
        pai[raiz2] = raiz1; 
        sz[raiz1] += sz[raiz2];

        componentes -= 1; 
        maximo = max(maximo, sz[raiz1]);

        return true;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    DSU dsu(n);
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b; 
        a--;b--;
        dsu.merge(a,b);
        cout << dsu.componentes << " " << dsu.maximo << endl;
    }
    return 0;
}