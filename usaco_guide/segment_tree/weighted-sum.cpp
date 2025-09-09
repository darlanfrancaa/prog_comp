#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

struct T{
    int sum, peso_sum;
};

struct SegTree{
    vector<T> tree;
    vector<int> lazy;
    SegTree(int n){
        tree.resize(4*n+10); lazy.resize(4*n+10);
    }

    T merge(T a, T b){
        return {a.sum + b.sum, a.peso_sum + b.peso_sum};
    }

    void build(int node, int ini, int fim, const vector<int> &v){
        if(ini== fim){
            tree[node] = {v[ini], v[ini]*ini};
            return;
        }
        int mid = (ini+fim)/2;
        build(2*node, ini, mid, v);
        build(2*node+1, mid+1, fim, v);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void refresh(int node, int ini, int fim){
        if(lazy[node] == 0) return;
        if(ini < fim){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        int soma1 = tree[node].sum + (fim-ini+1)*lazy[node];
        int soma2 = tree[node].peso_sum + (ini+fim) * (fim-ini+1) / 2 *lazy[node];
        tree[node] = {soma1, soma2};
        lazy[node] = 0;
    }

    void update(int node, int ini, int fim, int l,int r, int x){
        if(l<= ini && fim <= r){
            lazy[node] += x;
            refresh(node, ini, fim);
            return;
        }
        refresh(node, ini, fim);
        if(fim < l || ini > r) return; 

        int mid = (ini + fim)/2;
        update(2*node, ini, mid, l,r,x);
        update(2*node+1, mid+1, fim, l, r ,x);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
        return;
    }

    T query(int node, int ini, int fim , int l, int r){
        refresh(node,ini,fim);
        if(l <= ini && fim<= r) return tree[node];
        if(fim < l || ini > r) return {0,0};
        int mid = (ini+fim)/2;
        return merge(query(2*node,ini,mid,l,r), query(2*node+1, mid+1, fim, l, r));
    }
};



signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m; 
    vector<int> v(n+1);
    SegTree seg(n);
    for(int i=1;i<=n;i++) cin >> v[i];
    seg.build(1,1,n,v);
    for(int i=0;i<m;i++){
        int op; cin >> op; 
        if(op == 1){
            int a,b,val; cin >> a >> b >> val;
            seg.update(1,1,n,a,b,val);
        } else {
            int a,b; cin >> a >> b; 
            auto [soma, soma_peso] = seg.query(1,1,n,a,b);
            cout << soma_peso - (a-1) * soma << "\n";
        }
    }
    return 0;
}