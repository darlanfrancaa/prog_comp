#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int N = 1e5+10;
const int LOG = 20;
vector<int> adj[N];
int pai[N][LOG];
int tin[N], tout[N], timer = 1;

struct Node{
    int node;
    int idade; 
    int idx;
};
Node func[N];

void dfs_bin(int v,int p){
    tin[v] = timer++;
    pai[v][0] = p;
    for(int i=1;i<LOG;i++){
        if(pai[v][i-1] != 0){
            pai[v][i] = pai[pai[v][i-1]][i-1];
        }
    }
    for(auto node: adj[v]){
        if(node != p) dfs_bin(node, v);
    }
    tout[v] = timer-1;
}

struct Query{
    int tipo; // festa (1) pessoa (0)
    int idx;
    int idade;

    bool operator<(const Query& other) const {
        if(idade != other.idade) return idade < other.idade;
        return tipo > other.tipo;
    }
};

class SegTree{
private:
    int n; 
    vector<int> tree; 
    vector<int> lazy; 
public:

    SegTree(int k){
        n = k;
        tree.resize(4*n);
        lazy.resize(4*n);
    }

    void unlazy(int node, int l, int r){
        if(lazy[node] != 0){
            tree[node] += lazy[node] * (r-l+1);
            if(l != r){
                lazy[2*node] += lazy[node];
                lazy[2*node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val){
        unlazy(node, l, r);
        if(qr < l || r < ql) return; 
        if(ql <= l && r <= qr){
            lazy[node] += val;
            unlazy(node,l,r);
            return;
        }
        int mid = (l+r)/2;
        update(2*node,l,mid,ql,qr,val);
        update(2*node+1,mid+1,r, ql,qr, val);
        tree[node] = tree[2*node] + tree[2*node+1];
        return;
    }

    int query(int node, int l, int r, int ql, int qr){
        unlazy(node, l, r);
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return tree[node];
        int mid = (l+r)/2;
        return query(2*node, l, mid, ql,qr) +
               query(2*node + 1, mid+1, r, ql, qr);
    }

};



signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m; 
    int root = 1;
    for(int i = 1; i <= n; i++){
        int a, b; 
        cin >> a >> b; 
        func[i] = {b, a, i};
        if(b != i) {
            adj[b].push_back(i);
        } else {
            root = i;
        }
    }
    dfs_bin(root,root);
    vector<Query> queries;
    for(int i=1;i<=m;i++){
        int v, minimo, maximo; cin >> v >> minimo >> maximo;
        int curr = v; 
        for(int j = LOG-1; j>=0; j--){
            if(func[pai[curr][j]].idade <= maximo) curr = pai[curr][j];
        }
        // nova query vai ser curr, minimo de modo que um cara só está numa festa se ela tá na subárvore de curr e valor acima do mínimo
        Query nova = {1,curr,minimo};
        queries.push_back(nova);
    }
    for(int i=1;i<=n;i++){
        Query nova = {0,func[i].idx, func[i].idade};
        queries.push_back(nova);
    }
    SegTree seg(n+1);
    vector<int> ans(n+1);
    sort(queries.begin(), queries.end());
    for(auto &[tipo, idx, idade] : queries){
        if(tipo == 1){
            int curr = idx;
            int comeco = tin[curr], fim = tout[curr];
            seg.update(1,1,n,comeco, fim, 1);
        } else { 
            int resp = seg.query(1,1,n,tin[idx], tin[idx]);
            ans[idx] = resp;
        }
    }

    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }


    

    return 0;
}