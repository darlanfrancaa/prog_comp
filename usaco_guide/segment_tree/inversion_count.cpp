#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

struct Seg{
    vector<int> v,tree; 
    Seg(int n){
         v.resize(n+1,0); tree.resize(4*(n+1));
    }

    void build(int node, int l, int r){
        if(l==r){
            tree[node] = v[l];
            return;
        }
        int m = (l+r)/2;
        build(2*node,l, m);
        build(2*node+1, m+1, r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void update(int node, int l, int r, int pos, int val){
        if(l==r){ 
            tree[node] = val;
            return;
        }
        int m = (l+r)/2;
        if(pos <= m) update(2*node, l, m, pos, val);
        else update(2*node+1, m+1, r, pos, val);
        tree[node] = tree[2*node] + tree[2*node+1];
        return;
    }
    // quero quantos números na frente dele são maiores que ele;
    int query(int node, int l, int r, int nl, int nr){
        if(nl >= l && nr <= r) return tree[node];
        if(nl > r || nr < l) return 0; 
        int mid = (nl+nr)/2;
        return query(2*node,l, r, nl, mid) + query(2*node + 1, l , r, mid+1, nr);
    }


};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> vetor(n+1);
        map<int,int> mapa;
        for(int i=1;i<=n;i++) {
            cin >> vetor[i];
            mapa[vetor[i]] = i;
        }
        vector<int> sorted = vetor;
        sort(sorted.begin(), sorted.end());
        Seg seg(n);
        seg.build(1,1,n);
        int contador = 0;
        for(int i=1;i<=n;i++){
            int idx = mapa[sorted[i]];
            seg.update(1,1,n,idx,1);
            contador += seg.query(1,idx,n,1,n) - 1;
        }
    
        cout << contador << "\n";
    }
    return 0;
}