#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/2416

struct Node{
    int sum; 
    int max; 
    int ans; 
};

class SegTree{
private: 
    int n; 
    vector<Node> tree; 
public:

    void build(int node, int l, int r, vector<int> &v){
        if(l==r){
            tree[node] = {v[l], v[l], (int)0};
            return;
        }
        int mid = (l+r)/2;
        build(2*node, l , mid, v);
        build(2*node+1, mid+1, r, v);
        int max = v[l];
        int sum = v[l];
        int res = 0; 
        for(int i = l+1 ; i<= r;i++){
            if(v[i] > max) max = v[i];
            else res += (max - v[i]);
            sum += v[i];
        }
        tree[node] = {sum, max, res };
        return;
    }

    SegTree(int n, vector<int> &v){
        tree.resize(4*n);
        build(1,0,n-1, v);
    }

    pii search(int node, int l, int r, int val, vector<int> &v){ // eu quero saber o resultado de um intervalo caso o valor anterior a ele seja val
        if(l==r){
            if(v[l] >= val) return {0, v[l]};
            return {val-v[l], val};
        } 
        int mid = (l+r)/2; 
        if(tree[node].max <= val) return {val * (r-l+1) - tree[node].sum, val};
        if(tree[2*node].max >= val){ // então o primeiro cara maior que val está na esquerda
            auto [total, prox_maximo] = search(2*node, l, mid, val, v);
            return {total + tree[node].ans - tree[2*node].ans, tree[node].max};
        } else { // então o primeiro cara maior que val está na direita
            auto [total, prox_maximo] = search(2*node+1, mid+1, r, val, v);
            return {total + val * (mid-l+1) - tree[2*node].sum, tree[node].max};
        }
    }

    pii query(int node, int begin,int end, int l, int r, int val, vector<int> &v){
        if(begin > r || end < l) return {0,0};
        if(l <= begin && end <= r) {
            return search(node, begin,end, val, v);
        }
        int mid = (begin+end)/2;
        pii q1 = query(2*node, begin, mid, l,r , val, v);
        pii q2 = query(2*node+1, mid+1, end, l, r, q1.second , v);
        return {q1.first + q2.first, max(q1.second, q2.second)};
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, q; cin >> n >> q; 
    vector<int> v(n); 
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    SegTree seg(n,v);
    while(q--){
        int l, r; cin >> l >>r; 
        l--;r--; 
        cout<< seg.query(1,0,n-1, l,r,0, v).first << "\n";
    }
    return 0;
}