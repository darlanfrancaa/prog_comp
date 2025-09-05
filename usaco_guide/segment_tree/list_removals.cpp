#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int n; 

struct Seg{
    vector<int> tree;
    Seg(int n){
        tree.resize(4*n+10);
    }

    void build(const vector<int> &v, int node, int l , int r){
        if(l==r){
            tree[node] = v[l];
            return;
        }
        int mid = (l+r)/2;
        build(v,2*node,l,mid);
        build(v, 2*node+1,mid+1, r);
        tree[node]  = tree[2*node] + tree[2*node+1];
        return;
    }
    
    void build(const vector<int> &v){
        build(v,1,1,n);
    }

    void update(int node, int ini, int fim, int pos, int val){
        if(ini == fim){
            tree[node] = val;
            return;
        }
        int mid = (ini+fim)/2;
        if(pos <= mid) update(2*node, ini, mid , pos, val);
        else update(2*node+1, mid+1, fim, pos, val);
        tree[node] = tree[2*node] + tree[2*node + 1];
        return;
    }

    void update(int pos,int val){
        update(1,1,n,pos,val);
    }

    int query(int node, int ini, int fim , int l, int r){
        if(l<=ini && fim <= r) return tree[node];
        if(ini> r || fim < l) return 0;
        int mid = (ini+fim)/2;
        return query(2*node,ini,mid,l,r) + query(2*node+1, mid+1,fim,l,r);
    }

    int query(int l,int r){
        return query(1,1,n,l,r);
    }

    int find(int val){
        int l = 0, r = n;
        while(r - l > 1){
            int mid = (l+r)/2;
            if(query(1,mid) >= val) r = mid;
            else l = mid;
        } 
        return r;
    }

};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<int> r(n+1,1);
    Seg seg(n);
    seg.build(r);
    for(int i=0;i<n;i++){
        int a; cin >> a; 
        int idx = seg.find(a);
        cout << v[idx] << " ";
        seg.update(idx,0);    
    }



    return 0;
}