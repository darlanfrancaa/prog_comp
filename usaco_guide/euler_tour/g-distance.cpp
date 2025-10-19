#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int LOG = 21;
int n;

struct Aresta
{
    int u, v, w, idx;
};

vector<vector<int>> adj,dp;
vector<Aresta> ed;
vector<int> et, tin, tout, greater_vertex, values; 
vector<int> depth;
vector<int> sumr;

template <typename T> struct SegTree{
    int n; 
    vector<T> tree;
    T NEUTRO = 0;

    SegTree(const vector<T> &v){
        n = (int) v.size();
        tree.resize(4*n);
        build(v);
    }

    T merge(T &a, T &b){
        return a + b;
    }

    void build(int node, int ini, int fim, const vector<T> &v){
        if(ini == fim){
            tree[node] = v[ini];
            return;
        } 
        int mid = (ini + fim)/2;
        build(2*node, ini, mid, v);
        build(2*node+1, mid+1, fim, v);
        tree[node] = merge(tree[2*node+1], tree[2*node]);
        return;
    }

    void build(const vector<T> &v){
        build(1,0, n-1, v);
    }

    void update(int node, int ini, int fim, T val, int pos){
        if(ini == fim){
            tree[node] = val;
            return;
        }
        int mid = (ini+fim)/2;
        if(pos <= mid) update(2*node, ini, mid, val, pos);
        else update(2*node+1, mid+1, fim, val, pos);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
        return;
    }

    void update(int val, int pos){
        update(1, 0, n-1, val, pos);
    }

    T query(int node, int ini, int fim, int l, int r){
        if(l <= ini && fim <= r) return tree[node];
        if(ini > r || fim < l) return NEUTRO;
        int mid = (ini + fim)/2;
        T ans1 = query(2*node, ini, mid, l ,r);
        T ans2 = query(2*node+1, mid+1, fim, l ,r);
        return merge(ans1, ans2);
    }

    T query(int l, int r){
        return query(1, 0, n-1, l, r);
    }
};


int timer = 0;


void dfs(int p, int v, int d){
    if(tin[v] == 0) tin[v] = timer; 
    tout[v] = timer;
    depth[v] = d; 
    dp[v][0] = p;
    et[timer++] = v;

    for(auto &node: adj[v]){
        if(node != p) {
            dfs(v,node,d+1);
            et[timer] = v;
            tout[v] = timer++;
        }
    }
}

void fill_dp(){
    for(int j=1;j<LOG;j++){
        for(int i=0;i<n;i++){
            if(dp[i][j-1] != -1) dp[i][j] = dp[dp[i][j-1]][j-1];
            else dp[i][j] = -1; 
        }
    }
}

int up(int v, int k){
    for(int j=LOG-1;j>=0;j--){
        if(k & (1 << j)) {
            if(v == -1) return -1;
            v = dp[v][j];
        }
    }
    return v;
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    int diff = depth[u] - depth[v]; 
    u = up(u, diff); 
    if(u == v) return u; 
    for(int j=LOG-1;j>=0;j--){
        if(dp[u][j] != -1 && dp[u][j] != dp[v][j]){
            u = dp[u][j]; 
            v = dp[v][j];
        }
    }
    return dp[v][0];
}


signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    cin >> n; 
    adj.resize(n); ed.resize(n-1); tin.resize(n,0); tout.resize(n,0); et.resize(2*n-1); greater_vertex.resize(n-1); values.resize(n);
    sumr.resize(2*n); depth.resize(n);
    dp.resize(n, vector<int> (LOG,-1));
    for(int i=0;i<n-1;i++){
        int a,b,w; cin >> a >> b >> w; 
        adj[--a].push_back(--b); 
        adj[b].push_back(a);
        ed[i] = {a,b,w,i};
    }
    dfs(-1,0,0);
    fill_dp();
    for(auto [u,v,w,i]: ed){
        if(tin[u] > tin[v]) greater_vertex[i] = u;
        else greater_vertex[i] = v;
        values[greater_vertex[i]] = w;
    }
    timer = 0;
    for(int i=0;i<n;i++){
        sumr[tin[i]] += values[i];
        sumr[tout[i]+1] -= values[i];
    }

    SegTree seg(sumr);
    int q; cin >> q; 
    while(q--){
        int op; cin >> op; 
        if(op == 1){
            int edge, weight; cin >> edge >> weight;
            int v = greater_vertex[--edge];
            seg.update(weight, tin[v]);
            seg.update(-weight, tout[v]+1);
            values[v] = weight;
        }
        else {
            int u,v; cin >> u >> v; 
            u--;v--;
            int lc = lca(u,v);
            int ans1 = seg.query(0,tin[v]);
            int ans2 = seg.query(0,tin[u]);
            int ansl = seg.query(0,tin[lc]);
            cout << ans1 + ans2 - 2*ansl << "\n";
        }
    }
    
    return 0;
}