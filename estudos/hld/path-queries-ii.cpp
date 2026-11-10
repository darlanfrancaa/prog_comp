#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 2e5+10;

// problem link: https://cses.fi/problemset/task/2134

int t[4*MAXN];

int pull(int p){
    return t[p] = max(t[2*p], t[2*p+1]);
}

void build_seg(int p, int l, int r, vector<int> &v){
    if(l == r){
        t[p] = v[l];
        return;
    }
    int m = (l+r)/2; 
    build_seg(2*p, l, m,v);
    build_seg(2*p+1, m+1, r,v);
    pull(p);
}

void update_seg(int p, int l, int r, int pos, int val){
    if(l == r) {
        t[p] = val;
        return;
    }
    int m = (l+r)/2;
    if(pos <= m) update_seg(2*p, l, m, pos, val);
    else update_seg(2*p+1, m+1,r, pos, val);
    pull(p);
}

int query_seg(int p, int l, int r, int ql, int qr){
    if(r < ql || l > qr) return INT_MIN;
    if(ql <= l && r <= qr) return t[p];
    int m = (l+r)/2;
    int a = query_seg(2*p, l, m, ql, qr);
    int b = query_seg(2*p+1, m+1, r, ql, qr);
    return max(a,b);
}

vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN], sz[MAXN], par[MAXN], dep[MAXN], head[MAXN], heavy[MAXN], pos[MAXN];
int curr = 0;
int dfs(int p, int u){
    sz[u] = 1;
    int best = 0; 
    for(int v: adj[u]){
        if(v != p){
            par[v] = u; dep[v] = dep[u] + 1;
            int sub_v = dfs(u, v);
            sz[u] += sub_v;
            if(sz[v] > best){
                best = sub_v; heavy[u]= v;
            }
        }
    }
    return sz[u];
}

void decompose(int u, int h){
    head[u] = h; pos[u] = curr++;
    if(heavy[u] != -1) decompose(heavy[u], h);
    for(int v: adj[u]){
        if(v != par[u] && v != heavy[u]) decompose(v,v); 
    }
}

void build(int v){
    dfs(-1,v);
    decompose(v,v);
}

int query_path(int a, int b, int n){
    int res = INT_MIN;
    while(head[a] != head[b]){
        if(dep[head[a]] > dep[head[b]]) swap(a,b);
        res = max(res, query_seg(1,0,n-1,pos[head[b]], pos[b]));
        b = par[head[b]];
    }
    if(dep[a] > dep[b]) swap(a,b);
    res = max(res, query_seg(1,0,n-1, pos[a], pos[b]));
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    vector<int> v(n); 
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n-1;i++){
        int a, b; cin >> a >> b; 
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dep[0] = 0; 
    par[0] = 0;
    for(int i=0;i<n;i++){
        heavy[i] = -1;
    }
    build(0);
    vector<int> et(n);
    for(int i=0;i<n;i++){
        et[pos[i]] = v[i];
    }

    build_seg(1,0,n-1,et);
    while(q--){
        int op; 
        cin >> op;
        if(op == 1){
            int s, x; cin >> s >> x; s--; 
            update_seg(1,0,n-1,pos[s],x);
        } else {
            int a, b; cin >> a >> b; 
            a--;b--; 
            cout << query_path(a,b,n) << "\n";
        }
    }
    return 0;
}