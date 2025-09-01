#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int n = 1e5+10;
vector<int> v;

struct SegTree{
    int tree[4*n];
    int join(int a, int b){ 
        return a+b;
    }
    void build(int node, int l, int r){
        if(l == r){ 
            tree[node] = v[l];
            return;
        } 
        int mid = (l+r)/2;
        build(2*node, l, mid);
        build(2*node + 1, mid+1, r);
        tree[node] = join(tree[2*node], tree[2*node+1]);
        return;
    }
    void update(int node, int l, int r, int pos, int val){
        if(l==r){
            tree[node] = val;
            return;
        }
        int mid = (l+r)/2;
        if(pos<=mid) update(2*node, l,mid, pos, val);
        else update(2*node+1,mid+1, r, pos,val);
        tree[node] = join(tree[2*node], tree[2*node+1]);
        return;
    }
    int query(int node, int l, int r, int tl, int tr){
        if(l <= tl && tr <= tl) return tree[node];
        if(l > tr || r < tl) return 0;
        int mid = (tl + tr)/ 2; 
        return join(query(2*node, l,r,tl,mid), query(2*node+1,l,r,mid+1,tr));
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}