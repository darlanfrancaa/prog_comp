#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Seg{
    vector<int> v, tree;
    Seg(int n){
        v.resize(n+1);
        tree.resize(4*(n+1));
    }
    void atrib(int pos, int val){
        v[pos+1] = val;
    }

    void build(int node, int l, int r){
        if(l == r){ 
            tree[node] = v[l];
            return;
        }
        int mid = (l+r)/2; 
        build(2*node, l,mid);
        build(2*node+1, mid+1, r); 
        tree[node] = tree[2*node] + tree[2*node+1];
        return; 
    }

    void build(int n){
        build(1,1,n);
    }

    void update(int node, int l, int r, int pos, int val){
        if(l == r) {
            tree[node] = val;
            return; 
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(2*node, l,mid,pos,val);
        else update(2*node+1, mid+1, r, pos,val);
        tree[node] = tree[2*node] + tree[2*node + 1];
        return;
    }

    void update(int n, int pos, int val){ 
        update(1, 1,n, pos, val);
    }

    int query(int node, int l, int r, int tl, int tr){
        if(tl >= l && tr <= r ) return tree[node];
        if(tl > r || tr < l) return 0;
        int mid = (tl+tr)/2; 
        return query(2*node, l,r, tl, mid ) + query(2*node+1, l,r, mid+1, tr);
    }

    int query(int n, int l, int r){
        return query(1, l, r, 1, n);
    }

};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    Seg seg(n);
    for(int i=0;i<n;i++){
        int a; cin >> a; 
        seg.atrib(i,a);
    }
    seg.build(n);

    for(int i=0;i<q;i++){
        int op, a, b; cin >> op >> a >> b; 
        if(op == 1){
            seg.update(n,a,b);
        }
        else { 
            cout << seg.query(n,a,b) << "\n";
        }
    }

    return 0;
}