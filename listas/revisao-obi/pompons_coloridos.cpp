#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

struct Par{
    int maior, soma;
};

struct SegTree{
    vector<Par> tree;

    SegTree(int n){
        tree.resize(4*n+10);
    }

    Par merge(Par &a, Par &b){
        int soma = a.soma + b.soma;
        int maximo = max(a.maior, b.maior);
        return {maximo,soma};
    }

    void build(int node, int ini, int fim, const vector<int> &v){
        if(ini == fim){
            tree[node] = {v[ini], v[ini]};
            return;
        } 
        int mid = (ini+fim)/2;
        build(2*node, ini, mid, v);
        build(2*node +1, mid+1, fim , v);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
        return;
    }

    Par query(int node, int ini, int fim, int l, int r){
        if(l <= ini && fim <= r) return tree[node];
        if(ini > r || fim < l) return {LLONG_MIN, 0};
        int mid = (ini+fim)/2; 
        Par p1 = query(2*node, ini, mid, l, r);
        Par p2 = query(2*node+1, mid+1, fim , l, r);
        return merge(p1,p2);
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    SegTree seg(n); 
    seg.build(1,1,n,v);
    int q; cin >> q; 
    while(q--){
        int l, r; cin >> l >> r; 
        auto [maior, soma] = seg.query(1,1,n,l,r);
        int ans; 
        if(soma - maior > maior) ans = soma / 2;
        else { 
            ans = soma - maior;
        }
        cout << ans << "\n";
    }
    return 0;
}