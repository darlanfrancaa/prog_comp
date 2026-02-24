#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1137

const int N = 2e5+10;
int tin[N], tout[N], val[N];
vector<int> adj[N], et(2*N+10);
int timer = 1;


class SegTree{
private: 
    int n; 
    vector<int> tree;
public:
    void build(int node, int l, int r, vector<int> &v){
        if(l == r){
            tree[node] = v[l];
            return;
        } 
        int mid = (l+r)/2; 
        build(2*node, l, mid, v); 
        build(2*node+1, mid+1,r, v);
        tree[node] = tree[2*node] + tree[2*node + 1];
        return;
    }

    SegTree(int qntd, vector<int> &v){
        n = qntd;
        tree.resize(4*n);
        build(1,1,n,v);
    }

    void update(int node, int l, int r, int pos, int val){
        if(l == r){
            tree[node] = val;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(2*node, l, mid, pos, val); 
        else update(2*node+1, mid+1, r, pos, val);
        tree[node] = tree[2*node] + tree[2*node+1];
        return;
    }

    int query(int node, int begin, int end, int l, int r){
        if(l <= begin && end <= r) return tree[node];
        if(end < l || begin > r) return 0; 
        int mid = (begin + end)/2; 
        int j1 = query(2*node, begin, mid, l, r);
        int j2 = query(2*node + 1, mid+1, end, l, r); 
        return j1+j2; 
    }
};

void dfs(int node){
    et[timer] = val[node]; // coloco o valor do vértice que estamos andando
    // cout << "estou no node = " << node << " e coloquei o valor de et[timer] = et[" << timer << "] como " << val[node] << endl;
    tin[node] = timer++; 
    for(auto v: adj[node]){
        // cout << "estou no vizinho v = " << v << " de node e aqui, o tin[v] = " << tin[v] << endl;
        if(tin[v] == 0) dfs(v);
    }
    et[timer] = val[node];
    tout[node]=timer++;
    return;
}
// todos os vetores estão 1-indexados

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    for(int i=1;i<=n;i++){
        cin >> val[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1); // preenche et,tin,tout
    int tam = 2*n + 3;
    SegTree seg(tam,et);
    // for(int i=0;i<2*n + 2;i++){
    //     cout << et[i] << " ";
    // }
    while(q--){
        int op; cin >> op; 
        if(op == 1){
            int node, val; cin >> node >> val; 
            // cout << "estou no vértice node onde tin = " << tin[node] << " e o tout = " << tout[node] << endl;
            seg.update(1,1,tam,tin[node],val);
            seg.update(1,1,tam,tout[node],val);
        } else { 
            int node; cin >> node; 
            // cout << "estou no vértice node onde tin = " << tin[node] << " e o tout = " << tout[node] << endl;
            cout << seg.query(1,1,tam,tin[node], tout[node]) / 2  << endl; 
        }
    }

    
    return 0;
}