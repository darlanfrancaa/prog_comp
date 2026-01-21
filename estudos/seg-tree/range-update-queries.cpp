#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
int n, q;
const int N = 2e5+10;

vector<int> v;

class SegTree{
private: 
    int n;
    vector<int> tree, lazyadd, lazyset;
public:
    SegTree(int tamanho) {
        n = tamanho;
        tree.resize(4 * n, 0);
        lazyadd.resize(4 * n, 0);
        lazyset.resize(4 * n, 0);
    }

    int join(int a, int b){
        return a+b;
    }
    void unlazy(int node, int l, int r){
        if(lazyset[node] != 0){
            tree[node] = (r-l+1) * lazyset[node];
            if(l != r){
                lazyadd[2*node] = lazyadd[2*node+1] = 0;
                lazyset[2*node] = lazyset[2*node+1] = lazyset[node];
            }
            lazyset[node] = 0;
        }
        if(lazyadd[node] != 0){
            tree[node] += (r-l+1) * lazyadd[node];
            if(l!=r){
                lazyadd[2*node] += lazyadd[node];
                lazyadd[2*node+1] += lazyadd[node];
            }
            lazyadd[node] = 0;
        }
    }

    void build(int node, int l, int r){
        if(l == r){
            tree[node] = v[l]; 
            return;
        }
        int mid = (l+r)/2; 
        build(2*node, l, mid);
        build(2*node+1, mid+1, r); 
        tree[node] = tree[2*node] + tree[2*node + 1];
        return;
    }

    void updateset(int node, int begin, int end, int l, int r, int val){
        unlazy(node, begin, end);
        if(begin > r  || end < l) return; 
        if(l <= begin && end <= r){
            lazyset[node] = val;
            lazyadd[node] = 0;
            unlazy(node, begin, end);
            return;
        }
        int mid = (begin + end)/2; 
        updateset(2*node, begin,mid, l,r, val);
        updateset(2*node+1, mid+1,end, l,r, val);
        tree[node] = join(tree[2*node], tree[2*node+1]);
        return;
    }

    void updateadd(int node, int begin, int end, int l, int r, int val){
        unlazy(node, begin, end);
        if(begin > r || end < l) return; 
        if(l <= begin && end <= r){
            lazyadd[node] += val;
            unlazy(node, begin, end);
            return;
        }
        int mid = (begin+end)/2;
        updateadd(2*node, begin, mid, l,r, val);
        updateadd(2*node+1, mid+1, end, l, r, val);
        tree[node] = tree[2*node] + tree[2*node+1]; 
        return;
    }

    int query(int node, int begin, int end, int l, int r){
        unlazy(node, begin, end);
        if(begin > r || end < l) return 0;
        if(l <= begin && end <= r) return tree[node];
        int mid = (begin+end)/2;
        int j1  = query(2*node, begin, mid, l, r);
        int j2 = query(2*node+1, mid+1, end, l, r);
        return join(j1,j2);
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    v.resize(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    SegTree seg(n);
    seg.build(1,0,n-1);
    while(q--){
        int op; cin >> op; 
        if(op == 1){
            int l,r,u; cin >> l >> r >> u;
            l--;r--;
            seg.updateadd(1,0,n-1,l,r,u);
        }
        else {
            int l; cin >> l;
            l--;
            cout << seg.query(1,0,n-1,l,l) << "\n";
        }
    }
    return 0;
}