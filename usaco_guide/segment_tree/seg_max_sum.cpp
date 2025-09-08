#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link : https://cses.fi/problemset/task/3226/

struct T{
    int sum, max_prefix, max_suffix, max_subarry;
};

struct SegTree{
    vector<T> tree;
    SegTree(int n){
        tree.resize(4*n+1);
    }
    T merge(T left, T right){
        int mp = max(left.max_prefix, left.sum + right.max_prefix);
        int ms = max(right.max_suffix, right.sum + left.max_suffix);
        int ma = max({left.max_subarry, right.max_subarry, left.max_suffix + right.max_prefix});
        
        T ret = {left.sum + right.sum, mp, ms, ma};
        return ret;
    }
    void build(int node, int l, int r, const vector<int> &v){
        if(l == r){ 
            tree[node] = {v[l], max(0LL, v[l]), max(0LL, v[l]), max(0LL, v[l])};
            return;
        } 
        int mid = (l+r)/2;
        build(2*node, l, mid,v);
        build(2*node + 1, mid+1, r,v);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
        return;
    }
    void update(int node, int l, int r, int pos, int val){
        if(l==r){
            tree[node] = {val, max(0LL, val), max(0LL, val), max(0LL, val)};
            return;
        }
        int mid = (l+r)/2;
        if(pos<=mid) update(2*node, l,mid, pos, val);
        else update(2*node+1,mid+1, r, pos,val);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
        return;
    }
    T query(int node, int l, int r, int tl, int tr){
        if(l <= tl && tr <= r) return tree[node];
        if(l > tr || r < tl) return {0,LLONG_MIN, LLONG_MIN,LLONG_MIN};
        int mid = (tl + tr)/ 2; 
        return merge(query(2*node, l,r,tl,mid), query(2*node+1,l,r,mid+1,tr));
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    vector<int> v(n+1);
    for(int  i=1;i<=n;i++) cin >> v[i];
    SegTree seg(n);
    seg.build(1, 1, n, v);
    for(int i = 0; i < m; i++) {
        int k, x; cin >> k >> x;  
        seg.update(1, 1, n, k, x); 
        cout << seg.query(1, 1, n, 1, n).max_subarry << "\n";
    }
}