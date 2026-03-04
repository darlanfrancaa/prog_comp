#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10; 
const int LOG = 20;

int n, q; 
int up[N][LOG];
int v[N];
vector<int> adj[N];
int tin[N], tout[N];
vector<int> et;
int timer = 0;
int tree[4*N];
int lazy[4*N];
// problem link: https://neps.academy/exercise/2931

// eu preciso fazer o vetor do binlift
// e eu preciso fazer a segtree com lazy

void dfs(int u, int p) {
    tin[u] = ++timer; 
    up[u][0] = p;
    
    for (int i = 1; i < LOG; i++) {
        if (up[u][i-1] != 0)
            up[u][i] = up[up[u][i-1]][i-1];
        else 
            up[u][i] = 0;
    }

    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }
    tout[u] = timer;
}


void push(int node, int l, int r){
    if(lazy[node] != -1){
        tree[node] = lazy[node];
        if(l != r){
            lazy[2*node] = lazy[node];
            lazy[2*node + 1] = lazy[node];
        }
    lazy[node] = -1;
    }
}

void update(int node, int l,int r, int begin, int end){
    push(node,l,r);
    if(l > end || r < begin) return;
    if(l >= begin && r <= end){
        lazy[node] = 1;
        push(node,l,r);
        return;
    }
    int mid = (l + r)/2;
    update(2*node, l, mid, begin, end);
    update(2*node + 1, mid+1, r, begin, end);
    return;
    
}

int query(int node, int l, int r, int pos){
    push(node,l,r);
    if(l == r) return tree[node];
    int mid = (l+r)/2;
    if(pos <= mid) return query(2*node, l, mid,pos);
    else return query(2*node+1, mid+1,r, pos);
}


int query_ans(int u, int k){
    // a ideia é encontrar o primeiro cara tal que não é sofreu update
    int atualizado = query(1,1,n,tin[u]);

    int curr = u; 
    if(atualizado){
        for(int i = LOG - 1;i>=0;i--){
            int atual = up[curr][i];
            if(atual != 0){
                if(query(1,1,n,tin[atual]) == 1){
                    curr = atual;
                }
            }
        }
        curr = up[curr][0];
        k--;
    }
    if(curr == 0) return 0;
    for (int i = 0; i < LOG; i++) {
        if ((k >> i) & 1) {
            curr = up[curr][i];
        }
    }
    return curr;
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    cin >> n; 
    fill(lazy, lazy + 4 * N, -1);

    for(int i=2;i<=n;i++){
        int a; cin >> a; 
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    dfs(1,0);
    cin >> q; 
    while(q--){
        int op; cin >> op;
        if(op == 2){
            int x; cin >> x; 
            if(tin[x] < tout[x])
                update(1,1,n,tin[x]+1, tout[x]);
        } else {
            int x, k; cin >> x >> k;
            cout << query_ans(x,k) << endl;
        }
    }
    return 0;
}