#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

template <typename T> struct SparseTable{
    int n, log2dist;
    vector<vector<T>> st; 

    SparseTable(const vector<T> &v){
        n = v.size(); 
        log2dist = 1 + (int)log2(n);
        st.resize(log2dist);
        st[0] = v; 
        for(int i=1;i<log2dist;i++){
            st[i].resize(n - (1 << i) + 1);
            for(int j=0;j+(1 << i) <= n;j++){
                st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
            }
        }
    }

    T query(int l, int r){
        int i = (int)log2(r-l+1);
        return min(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

class LCA{
    private:    
        int n; 
        vector<vector<int>> adj;
        SparseTable<pii> rmq;
        vector<int> tin, et, dep; 
        int timer = 0; 

        void dfs(int u, int p){
            tin[u] = timer;
            et[timer++] = u;
            for(int v : adj[u]){
                if(v != p){
                    dep[v] = dep[u] + 1;
                    dfs(v,u);
                    et[timer++] = u;
                }
            }
        }
    public: 
        LCA(vector<vector<int>> &_adj): n((int)_adj.size()), adj(_adj), tin(n), et(2*n), dep(n), rmq(vector<pair<int,int>>(1)){
            dfs(0,-1);
            vector<pair<int, int>> arr(2 * n - 1);
            for (int i = 0; i < 2 * n - 1; i++) { arr[i] = {dep[et[i]], et[i]}; }
            rmq = SparseTable<pair<int, int>>(arr);
        }

        int query(int a, int b) {

		    if (tin[a] > tin[b]) { swap(a, b); }

		    return rmq.query(tin[a], tin[b]).second;

	    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    vector<vector<int>> adj(n);
    for (int i = 2; i <= n; i++) {
        int u, v; cin >> u;
        v = i;
        u--; v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    LCA lca(adj);
    while(q--){
        int u, v; cin >> u >> v; 
        u--;v--; 
        int ancestral = lca.query(u,v);
        cout << ancestral + 1 << "\n";
    }
    
    return 0;
}