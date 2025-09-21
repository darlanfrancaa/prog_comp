#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
int n;

struct Par{
    int idx, maior;
};

struct SegTree{
    vector<Par> tree;

    SegTree(int n){
        tree.resize(4*n+10);
    }

    Par join(Par &a, Par &b){ 
        if(a.maior > b.maior){
            Par ret = {a.idx,a.maior}; 
            return ret;
        } else return {b.idx, b.maior};
    }

    void build(int node, int l, int r, const vector<int> &v ){
        if(l == r){ 
            tree[node] = {l,v[l]};
            return;
        } 
        int mid = (l+r)/2;
        build(2*node, l, mid,v);
        build(2*node + 1, mid+1, r,v);
        tree[node] = join(tree[2*node], tree[2*node+1]);
        return;
    }

    Par query(int node, int l, int r, int tl, int tr){
        if(l <= tl && tr <= r) return tree[node];
        if(l > tr || r < tl) return {-1,LLONG_MIN};
        int mid = (tl + tr)/ 2; 
        Par p1 = query(2*node, l,r,tl,mid);
        Par p2 = query(2*node+1,l,r,mid+1,tr);
        return join(p1,p2);
    }
};


int solve(const vector<int> &v, int n, int ini, int fim, SegTree &seg){
    if(ini > fim) return 0;
    if(ini == fim){
        int a = v[ini] * (v[ini]+1) /2;
        return a;
    }
    if(ini < 0 || fim >=n) return 0;
    auto [idx_maior, maior] = seg.query(1,ini,fim,0, n-1);
    int a = idx_maior - ini;
    int b = fim - idx_maior;
    int num = (maior * ((maior+1) % MOD) /2) % MOD;
    int ret = 0; 
    ret += ((((a * b + a + b) % MOD) * num) % MOD);
    int lado_e = solve(v, n, ini, idx_maior-1,seg) % MOD;
    int lado_d = solve(v,n,idx_maior+1,fim,seg) % MOD;
    ret = (ret + lado_e) % MOD;
    ret = (ret + lado_d) % MOD;
    ret = (ret + num) % MOD;
    return ret;
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> v(n); 
    for(auto &a: v) cin >> a; 
    SegTree seg(n);
    seg.build(1,0,n-1,v);
    cout << solve(v,n,0,n-1,seg);
    return 0;
}