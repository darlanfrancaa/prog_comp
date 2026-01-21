#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1736

int sumton(int n){
    return n * (n+1) / 2;
}

int sum_range(int a, int b){
    if(a > b) return 0; 
    return sumton(b) - sumton(a-1);
}

class SegTree{
private: 
    int n; 
    vector<int> tree, lazyqntd, lazysum;
public:
    
    void build(int node, int l ,int r, vector<int> &v){
        if(l==r){
            tree[node] = v[l];
            return; 
        }
        int mid = (l+r)/2;
        build(2*node, l , mid , v);
        build(2*node+1, mid+1, r, v); 
        tree[node] = tree[2*node] + tree[2*node+1];
        return;
    }

    SegTree(int n , vector<int> &v){
        tree.resize(4*n); 
        lazyqntd.resize(4*n); 
        lazysum.resize(4*n);
        build(1, 0, n-1, v);
    }

void unlazy(int node, int begin, int end){
        int soma_indices = sum_range(begin + 1, end + 1);
        int res_qntd = lazyqntd[node] * soma_indices;
    
        int tamanho = (end - begin + 1);
        int res_sum = lazysum[node] * tamanho;

        tree[node] += res_qntd - res_sum; 
        if(begin != end){
     
            lazyqntd[2*node] += lazyqntd[node];
            lazyqntd[2*node+1] += lazyqntd[node];
            
            lazysum[2*node] += lazysum[node];
            lazysum[2*node+1] += lazysum[node];
        }
        
        lazyqntd[node] = 0; 
        lazysum[node] = 0;
    }

    void update(int node, int begin, int end, int l, int r){
        unlazy(node, begin, end);
        if(begin > r || end < l) return;
        if(l <= begin && end <= r){
            lazyqntd[node]++; 
            lazysum[node]+=l;
            unlazy(node, begin, end);
            return;
        }
        int mid = (begin + end)/2;
        update(2*node, begin, mid ,l, r);
        update(2*node+1, mid+1, end, l,r);
        tree[node] = tree[2*node] + tree[2*node+1];
        return;
    }

    int query(int node, int begin, int end, int l , int r){
        unlazy(node, begin , end);
        if(begin > r || end < l) return 0; 
        if(l <= begin && end <= r) return tree[node];
        int mid = (begin+end)/2;
        int q1 = query(2*node, begin , mid, l,r);
        int q2 = query(2*node+1, mid+1, end, l, r);
        return q1+q2;
    }

};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q; cin >> n >> q; 
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    SegTree seg(n, v);
    while(q--){
        int op, l, r; cin >> op >> l >> r;
        l--; r--;
        if(op == 1){
            seg.update(1,0,n-1,l,r);
        } else { 
            int ans = seg.query(1,0,n-1, l, r);
            cout << ans << '\n';
        }
    }

    return 0;
}