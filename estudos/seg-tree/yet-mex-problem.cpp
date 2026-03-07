#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/2146/E

class SegTree{
private:
    int n; 
    vector<int> tree, lazy;
public:
    SegTree(int k){
        n = k; 
        tree.resize(4*n);
        lazy.resize(4*n);
    }

    void unlazy(int node, int l, int r) {
        if (lazy[node] != 0) {
            if (l != r) { 
                tree[2*node] += lazy[node];
                lazy[2*node] += lazy[node];
                
                tree[2*node + 1] += lazy[node];
                lazy[2*node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateadd(int node, int begin, int end, int l, int r, int val){
        if(begin > r || end < l) return; 
        unlazy(node, begin, end);
        if(l <= begin && end <= r){
            tree[node] += val;
            lazy[node] += val;
            unlazy(node, begin, end);
            return;
        }
        int mid = (begin+end)/2;
        updateadd(2*node, begin, mid, l,r, val);
        updateadd(2*node+1, mid+1, end, l, r, val);
        tree[node] = max(tree[2*node] , tree[2*node+1]) ;
        return;
    }

    void set_val(int node, int l, int r, int pos, int val){
        if(l==r){
            tree[node] = val; 
            lazy[node] = 0;
            return;
        }

        unlazy(node, l,r);
        int mid = (l+r)/2;
        if(pos <= mid) set_val(2*node,l,mid,pos,val);
        else set_val(2*node+1,mid+1,r,pos,val);

        tree[node] = max(tree[2*node], tree[2*node+1]);
        return;
    }

    int query_max() {
        return tree[1];
    }
};

void solve(){
    int n; cin >> n; 
    SegTree st(n+1);
    for(int i=0;i<n;i++){
        int a; cin >> a; 
        st.set_val(1,0,n,a,0);
        if(a > 0){
            st.updateadd(1,0,n,0,a-1,1);
        }

        cout << st.query_max() << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}