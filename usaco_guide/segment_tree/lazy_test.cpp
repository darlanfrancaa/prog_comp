#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

vector<int> tree, lazy_s, lazy_c;
vector<bool> is_lazy_c;

void build(const vector<int> &v, int node, int l,int r){
    if(l==r) {
        tree[node] = v[l];
        return;
    }
    int mid = (l+r)/2;
    build(v,2*node,l,mid);
    build(v,2*node+1, mid+1, r);
    tree[node] = tree[2*node] + tree[2*node+1];
    return;
}

void push(int node, int l, int r){
    if(is_lazy_c[node]){
        tree[node] = lazy_c[node] * (r-l+1);
        if(r > l){
            is_lazy_c[2*node] = true;
            lazy_c[2*node] = lazy_c[node];
            lazy_s[2*node] = 0; 

            is_lazy_c[2*node+1] = true;
            lazy_c[2*node+1] = lazy_c[node];
            lazy_s[2*node+1] = 0;
        }
        is_lazy_c[node] = false;
        lazy_c[node] = 0;
        return;
    }

    if(lazy_s[node] != 0){
        tree[node] += lazy_s[node] * (r-l+1);
        if(r > l){
            if (is_lazy_c[2*node]) {
                lazy_c[2*node] += lazy_s[node];
            } else { 
                lazy_s[2*node] += lazy_s[node];
            }

            if (is_lazy_c[2*node+1]) {
                lazy_c[2*node+1] += lazy_s[node];
            } else {
                lazy_s[2*node+1] += lazy_s[node];
            }
        }
        lazy_s[node] = 0;
        return;
    }


}


void update_change(int node, int ini, int fim , int l, int r , int x){
    push(node,ini,fim);
    if(l<=ini && fim <= r){
        is_lazy_c[node] = true;
        lazy_c[node] = x;
        lazy_s[node] = 0;
        push(node, ini,fim);
        return;
    }
    if(ini > r || fim < l) return;
    int mid = (ini+fim)/2;
    update_change(2*node,ini,mid,l,r,x);
    update_change(2*node+1,mid+1,fim,l,r,x);
    tree[node] = tree[2*node] + tree[2*node+1];
    return;
}

void update_sum(int node, int ini, int fim , int l, int r , int x){
    push(node,ini,fim);
    if(l<=ini && fim <= r){
        lazy_s[node] += x;
        push(node, ini,fim);
        return;
    }
    if(ini > r || fim < l) return;
    int mid = (ini+fim)/2;
    update_sum(2*node,ini,mid,l,r,x);
    update_sum(2*node+1,mid+1,fim,l,r,x);
    tree[node] = tree[2*node] + tree[2*node+1];
    return;
}


int query(int node, int ini, int fim , int l, int r){
    push(node,ini,fim);
    if(l<=ini && fim <= r) return tree[node];
    if(ini > r || fim < l) return 0;
    int mid = (ini + fim)/2;
    return query(2*node, ini, mid, l ,r) + query(2*node + 1, mid+1, fim , l ,r);

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    tree.resize(4*(n+1)); lazy_s.resize(4*(n+1)), lazy_c.resize(4*(n+1));
    is_lazy_c.resize(4*(n+1));
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    build(v,1,1,n);
    for(int i=0;i<q;i++){
        int op; cin >> op; 
        if(op == 3){ 
            int a,b; cin >> a >> b;
            cout << query(1,1,n,a,b) << "\n";
        }
        else if(op == 2){
            int a,b,v; cin >> a >> b >> v; 
            update_change(1,1,n,a,b,v);
        }
        else { 
            int a,b,v; cin >> a >> b >> v;
            update_sum(1,1,n,a,b,v);
        }
    }
    return 0;
}