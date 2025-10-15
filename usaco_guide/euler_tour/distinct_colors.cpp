#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

struct Query{
    int l, r, idx;
};

struct CompareQuery{
    bool operator()(const Query &a, const Query &b){
        return a.r < b.r;
    }
};

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

    void update(int node, int ini, int fim, int val, int pos){
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

vector<vector<int>> adj; 
vector<int> et, first, last, colors;
int timer = 0;

void dfs(int p, int v){
    if(first[v] == -1) first[v] = timer;
    last[v] = timer;
    et[timer++] = v;
    for(auto &node: adj[v]){
        if(node != p){
            dfs(v, node);
            et[timer] = v; 
            last[v] = timer++;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    et.resize(2*n -1); first.resize(n,-1); last.resize(n); adj.resize(n); colors.resize(n);
    for(int i=0;i<n;i++){
        cin >> colors[i];
    }
    for(int i=0;i<n-1;i++){
        int a, b; cin >> a >> b; 
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    dfs(-1,0);
    vector<int> et_color (2 * n - 1);
    for(int i=0;i<et_color.size(); i++){
        et_color[i] = colors[et[i]];
    }
    vector<Query> queries; 
    for(int i=0;i<n;i++){
        queries.push_back({first[i], last[i], i});
    }
    sort(queries.begin(), queries.end(), CompareQuery());
    vector<int> ans(n);
    SegTree<int> seg(et_color);
    map<int,int> last_pos; 
    int qntd_query = 0;
    for(int i=0;i<et_color.size();i++){
        if(last_pos.count(et_color[i])){
            seg.update(0,last_pos[et_color[i]]);
        }
        seg.update(1,i);
        last_pos[et_color[i]] = i;
        while(qntd_query < n && queries[qntd_query].r == i){
            auto [left, right, index] = queries[qntd_query];
            ans[index] = seg.query(left, right);
            qntd_query++;
        }
    }

    for(int i=0;i<queries.size();i++){
        cout << ans[i] << " ";
    }




    return 0;
}