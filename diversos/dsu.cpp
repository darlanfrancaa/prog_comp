#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct DSU{
    vector<int> parent; 

    DSU(int n){ 
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int i){
        if(parent[i]==i){
            return i;
        }
        return find(parent[i]);
    }
    
    void unit(int i,int j){
        int raiz_i = find(i);
        int raiz_j = find(j);
        if(raiz_i != raiz_j){
            parent[raiz_i] = raiz_j;
        }
    }
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