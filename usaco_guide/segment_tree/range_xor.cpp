#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
#define int long long
vector<int> tree;

void build(vector<int> &v, int node, int l ,int r){ 
    if(l==r) {
        tree[node] = v[l];
        return; 
    }
    int m = (l+r)/2;
    build(v,2*node, l, m); 
    build(v,2*node+1,m+1,r);
    tree[node] = tree[2*node] ^ tree[2*node+1];
}

int query(vector<int> &v, int node, int l, int r, int nl, int nr){
    if(nl >= l && nr <= r) return tree[node];
    if(nl > r || nr < l) return 0;
    int m = (nl+nr)/2;
    return query(v,2*node, l,r, nl, m) ^ query(v, 2*node+1, l,r,m+1, nr);
}

int n;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n; int q; cin >> q; 
    vector<int> nums(n+1);
    tree.resize(4*(n+1));
    for(int i=1;i<=n;i++){
        cin >> nums[i];
    }
    build(nums,1,1,n);
    for(int i=0;i<q;i++){
        int a, b; cin >> a >> b; 
        cout << query(nums,1,a,b,1,n) << "\n";
    }

    return 0;
}