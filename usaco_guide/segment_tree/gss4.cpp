#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

struct Seg{
    vector<int> tree; 
    int n;
    Seg(int m){
        tree.resize(4*m+10);
        n = m;
    }

    void build(int node, int ini, int fim, const vector<int>& v){
        if(ini == fim){
            tree[node] = v[ini];
            return;
        }
        int mid = (ini+fim)/2;
        build(2*node, ini, mid, v);
        build(2*node+1, mid+1, fim, v);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void build(const vector<int>& v){
        build(1, 1, n, v);
    }

    void update(int node, int ini, int fim, int l, int r){
        if(ini > r || fim < l) return;
        if(tree[node] == (fim - ini +1)) return; 
        if(ini == fim){
            tree[node] = floor(sqrt(tree[node]));
            return;
        }
        int mid = (ini+fim)/2;
        update(2*node, ini, mid, l , r);
        update(2*node+1, mid+1, fim, l , r);
        tree[node] = tree[2*node] + tree[2*node + 1];
        return;
    }

    void update(int l, int r){
        update(1,1,n,l,r);
    }

    int query(int node, int ini, int fim, int l, int r){
        if(l<= ini && fim<= r) return tree[node];
        if(ini> r || fim < l) return 0; 
        int mid = (ini+fim)/2;
        return query(2*node, ini, mid, l , r) + query(2*node+1, mid +1, fim, l ,r);
    }

    int query(int l, int r){
        return query(1,1,n,l,r);
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, contador = 1;
    while(cin >> n){
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
        }
        
        Seg seg(n);
        seg.build(v);
        int q; cin >> q; 
        cout << "Case #" << contador << "\n";
        while(q--){
            int op, a , b; cin >> op >> a >> b;
            if(a > b) swap(a,b);
            if(op == 1){
                cout << seg.query(a,b) << "\n";
            } else { 
                seg.update(a,b);
            }
        }
        contador++;
        cout << "\n";
    }
    return 0;
}