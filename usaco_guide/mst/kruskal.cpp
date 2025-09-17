#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

struct DSU{
    vector<int> parents; 
    vector<int> sizes;

    DSU(int n){
        parents.resize(n);
        sizes.resize(n,1);
        for(int i=0;i<n;i++){
            parents[i] = i;
        }
    }
    int find(int x){
        if(parents[x] == x) return x;
        else return parents[x] = find(parents[x]);
    }

    bool unite(int x, int y){
        int x_root = find(x); int y_root = find(y);
        if(x_root == y_root) return false;
        if(sizes[x] < sizes[y]) swap(x_root, y_root);
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }

    bool connected(int a, int b){
        return find(a) == find(b);
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    struct Road{
        int c1, c2; 
        int cost; 
    };
    vector<Road> roads(m);
    for(Road &r: roads) {
        cin >> r.c1 >> r.c2 >> r.cost;
        r.c1--;
        r.c2--;
    }
    sort(roads.begin(), roads.end(),
                    [&](const Road &e1, const Road &e2){return e1.cost < e2.cost;});
    DSU dsu(n);
    int minimo = 0;
    int added = 0;
    for(Road &r: roads){
        bool status = dsu.unite(r.c1, r.c2);
        minimo += status * r.cost; 
        added += status;
    }

    if(added != n-1){
        cout << "IMPOSSIBLE\n";
    } else { 
        cout << minimo << "\n";
    }
    return 0;
}