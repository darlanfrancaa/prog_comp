#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct DSU
{
    vector<int> parent;
    vector<int> sz;

    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        sz.resize(n,1);
    }

    int find(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    bool unite(int a,int b){
        int raiz1 = find(a);
        int raiz2 = find(b);
        if(raiz1 == raiz2) return false;
        if(sz[raiz1] < sz[raiz2]){
            swap(raiz1,raiz2);
        }
        parent[raiz2] = raiz1;
        sz[raiz1] += sz[raiz2];
        return true;
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    DSU dsu(5);

    dsu.unite(0, 1);
    dsu.unite(2, 3);

    std::cout << "Representante do conjunto de 0: " << dsu.find(0) << std::endl;
    std::cout << "Representante do conjunto de 1: " << dsu.find(1) << std::endl;
    std::cout << "0 e 1 estão no mesmo conjunto? " << (dsu.find(0) == dsu.find(1) ? "Sim" : "Não") << std::endl;
    std::cout << "1 e 2 estão no mesmo conjunto? " << (dsu.find(1) == dsu.find(2) ? "Sim" : "Não") << std::endl;

    dsu.unite(0, 3);

    std::cout << "\nApós unir 0 e 3:\n";
    std::cout << "1 e 2 estão no mesmo conjunto? " << (dsu.find(1) == dsu.find(2) ? "Sim" : "Não") << std::endl;
    std::cout << "Representante do conjunto de 3: " << dsu.find(3) << std::endl;

    return 0;
}