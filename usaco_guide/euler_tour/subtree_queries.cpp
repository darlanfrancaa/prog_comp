#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

vector<vector<int>> vizinhos; 
vector<int> start;
vector<int> fim;
vector<int> flat_valores;
int timer = 1; 

struct SegTree{
    vector<int> tree;

    SegTree(int n){
        tree.resize(4*n + 10);
    }

    void build(int node, int ini, int fim , const vector<int>&v){
        if(ini == fim) {
            tree[node] = v[ini];
            return;
        }
        int mid = (ini+fim)/2;
        build(2*node, ini, mid, v);
        build(2*node+1, mid+1, fim, v);
        tree[node] = tree[2*node] + tree[2*node+1];
        return;
    }

    void update(int node, int ini, int fim, int pos, int val){
        if(ini == fim){
            tree[node] = val;
            return;
        }
        int mid = (ini+fim)/2;
        if(pos <= mid) update(2*node, ini, mid, pos, val); 
        else update(2*node+1, mid+1, fim, pos, val);
        tree[node] = tree[2*node] + tree[2*node+1];
        return;
    }

    int query(int node, int ini, int fim, int l, int r){
        if(l <= ini && fim <= r) return tree[node];
        if(ini > r || fim < l) return 0;
        int mid = (ini+fim)/2;
        return query(2*node, ini,mid,l,r) + query(2*node+1, mid+1,fim,l,r);
    }
};

void euler_tour(int at, int prev, const vector<int>& valores){
    start[at] = timer;         
    flat_valores[timer] = valores[at];   
    timer++;           

    for(int vizinho : vizinhos[at]){
        if(vizinho != prev) {
            euler_tour(vizinho, at, valores);
        }
    }
    fim[at] = timer;    
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> valores(n+1);
    flat_valores.resize(n+1);
    for(int i=1;i<=n;i++) cin >> valores[i];
    vizinhos.resize(n+1);
    for(int e = 0; e < n-1; e++){
        int a, b; cin >> a >>b; 
        vizinhos[a].push_back(b);
        vizinhos[b].push_back(a);
    }
    start.resize(n+1);
    fim.resize(n+1);
    euler_tour(1,-1,valores);
    cout << "\n";
    for(int i=1;i<=n;i++){
        cout << flat_valores[i] << " ";
    }
    cout << "\n";
    for(int i=1;i<=n;i++){
        cout << start[i] << " ";
    }
    cout << "\n";
    for(int i=1;i<=n;i++){
        cout << fim[i] << " ";
    }
    // SegTree seg(n);

    // seg.build(1,1,n,flat_valores);
    // for(int i=0;i<q;i++){
    //     int op; cin >> op; 
    //     if(op == 1){
    //         int node, val; cin >> node >> val; 
    //         seg.update(1,1,n,start[node],val);
    //     } else {
    //         int node; cin >> node;
    //         cout << seg.query(1,1,n,start[node], fim[node]) << "\n";
    //     }
    // }
    return 0;
}