#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

template <typename T> struct SegTree{
    int n; 
    vector<T> tree;
    vector<T> lazy;
    T NEUTRO = 0;
    T NO_OP = 0;

    SegTree(const vector<T> &v){
        n = (int) v.size();
        tree.resize(4*n);
        lazy.resize(4*n, NO_OP);
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

    void push(int node, int ini, int fim){
        if(lazy[node] == NO_OP) return;
        tree[node] += (fim-ini+1) * lazy[node];
        if(ini != fim){
            lazy[2*node] += lazy[node];
            lazy[2*node + 1] += lazy[node];
        }
        lazy[node] = NO_OP;
    }

    void update(int node, int ini, int fim, int l, int r, T val){

        push(node,ini,fim);

        if(ini > r || fim < l) return ;

        if(l <= ini && fim <= r){
            lazy[node] += val;
            return;
        }

        int mid = (ini+fim)/2;
        update(2 *node, ini, mid, l , r, val);
        update(2 * node + 1, mid + 1, fim, l , r , val);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
        return;
    }

    void update(int l, int r, T val){
        update(1, 0, n-1, l, r, val);
    }

    T query(int node, int ini, int fim, int l, int r){
        push(node, ini, fim);
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

vector<vector<int>> adj; 
vector<int> et, first, last, valores, sum;
int timer = 0;

void dfs(int p, int v){
    if(first[v] == -1) first[v] = timer;
    last[v] = timer;
    et[timer++] = v;
    // printf("entrei no vertice %lld\n", v);
    for(auto &node: adj[v]){
        // printf("estou visitando os filhos do vertice %lld\n", v);
        if(node != p){
            sum[node] = sum[v] + valores[node];
            // printf("eu estou visitando o filho %lld cujo valor da soma até ele é %lld\n", node, sum[node]);
            dfs(v, node);
            et[timer] = v; 
            last[v] = timer++;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    et.resize(2*n -1); first.resize(n,-1); last.resize(n); adj.resize(n); valores.resize(n); sum.resize(n);
    for(int i=0;i<n;i++){
        cin >> valores[i];
    }
    for(int i=0;i<n-1;i++){
        int a, b; cin >> a >> b; 
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    sum[0] = valores[0];
    dfs(-1,0);
    vector<int> et_nums(2*n-1);
    for(int i=0;i<et.size();i++){
        et_nums[i] = sum[et[i]];
    }
    SegTree seg(et_nums);
    for(int i=0;i<q;i++){
        int op; cin >> op; 
        if(op == 1){
            int vtx, value; cin >> vtx >> value;
            vtx--;
            int delta = value - valores[vtx];
            seg.update(first[vtx], last[vtx], delta);
            valores[vtx] = value;;
        } else { 
            int vtx; cin >> vtx; 
            vtx--;
            cout << seg.query(first[vtx], first[vtx]) << "\n";
        }
    }
    return 0;
}