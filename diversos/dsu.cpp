#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct DSU{
    vector<int> parent; 
    vector<int> sz;

    DSU(int n){ 
        parent.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        sz.assign(n,1);
    }

    int find(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    
    bool unit(int i,int j){
        int raiz_i = find(i);
        int raiz_j = find(j);
        if (raiz_i == raiz_j) return false;
        if(raiz_i != raiz_j){
            if(sz[raiz_i] <  sz[raiz_j]){
                swap(raiz_i, raiz_j);
            }
            parent[raiz_j] = raiz_i;
            sz[raiz_i]+= sz[raiz_j];
        }
        return true;
    }

    bool connected(int x, int y) {return find(x) == find(y);}
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    DSU grafo(n);
    while(q--){
        int op, a, b; cin >> op >> a >> b; 
        if(op == 0){
            grafo.unit(a,b);
        }
        else { 
            if(grafo.find(a) == grafo.find(b)) cout << 1 << endl; 
            else cout << 0 << endl; 
        }
    }

    return 0;
}