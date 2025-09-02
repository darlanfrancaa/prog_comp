#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

vector<int> v; 
int n; 

struct Seg{
    vector<int> tree;

    Seg(int n) {
        tree.resize(4*n, LLONG_MAX);
    }

    int join(int a,int b) {return min(a,b);}

    void build(int node, int l, int r){ 
        if(l == r){ 
            tree[node] = v[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        tree[node] = join(tree[2*node], tree[2*node+1]);
        return;  
    }

    void update(int node, int l, int r, int pos ,int val){
        if(l == r){ 
            tree[node] = val;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(2*node, l, mid, pos, val);
        else update(2*node+1, mid+1, r, pos, val);
        tree[node] = join(tree[2*node], tree[2*node+1]);
        return;
    }

    int query(int node, int l, int r, int tl, int tr){ 
        if(tl>= l && tr<= r) return tree[node];
        if(tl>r || tr < l) return LLONG_MAX;
        int mid = (tl+tr)/2;
        return join(query(2*node, l,r,tl,mid), query(2*node+1, l,r,mid+1,tr));
    }

};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin >> n >> q; 
    v.resize(n+2);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    } 
    Seg seg(n);
    seg.build(1,1,n);
    

    while(q--){
        int op, a , b; cin >> op >> a >> b;
        if(op == 1){ 
            seg.update(1,1,n,a,b);
        } else { 
            cout << seg.query(1,a,b,1,n) << "\n";
        }
    }
    
    return 0;
}