#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
#define int long long 

int n,m;
vector<int> h;

struct Seg{
    vector<int> tree;
    Seg(int n){ 
        h.resize(n+1);
        tree.resize(4*(n+1),LLONG_MIN);
    }

    void build(int node, int l, int r){ 
        if(l==r) { 
            tree[node] = h[l];
            return;
        }
        int m = (l+r)/2;
        build(2*node, l, m);
        build(2*node + 1, m+1, r);
        tree[node] = max(tree[2*node], tree[2*node+1]);
        return;
    }

    void build() {
        build(1,1,n);
    }

    void update(int node, int l, int r, int pos , int val){ 
        if(l==r){
            tree[node] -= val;
            return; 
        }
        int m = (l+r)/2; 
        if(pos <= m) update(2*node, l, m, pos, val);
        else update(2*node+1,m+1, r, pos, val);
        tree[node] = max(tree[2*node], tree[2*node+1]);
        return;
    }

    int search(int node, int l, int r, int val){ 
        if(tree[node] < val) return 0;
        if(l==r){
            return l; 
        }
        int m = (l+r)/2; 
        if(tree[2*node]>=val) return search(2*node,l,m,val);
        return search(2*node+1, m+1, r, val);
    }
};


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; 
    Seg seg(n);
    for(int i=1;i<=n;i++){
        cin >> h[i];
    }
    seg.build();
    vector<int> g(m);
    for(auto &m1: g) cin >> m1; 
    for(int i=0;i<m;i++){
        int atual = g[i];
        int ans = seg.search(1,1,n,atual);
        if (ans != 0) seg.update(1,1,n,ans, atual);
        cout << ans << " ";
    }
    return 0;
}