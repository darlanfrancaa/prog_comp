#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link : https://www.spoj.com/problems/DQUERY/

struct Seg{
    vector<int> tree; 

    Seg(int n){
        tree.resize(4*(n+1));
    }

    void build(int node, int ini, int fim, const vector<int> &v){
        if(ini == fim){
            tree[node] = v[ini];
            return;
        }
        int mid = (ini+fim)/2;
        build(2*node, ini, mid, v);
        build(2*node+1, mid+1, fim, v);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void update(int node, int ini, int fim, int pos , int val){
        if(ini == fim){
            tree[node] = val;
            return;
        }
        int mid = (ini+fim)/2;
        if(pos<=mid) update(2*node, ini, mid, pos, val);
        else update(2*node+1, mid+1, fim, pos, val);
        tree[node]  = tree[2*node] + tree[2*node+1];
        return;
    }

    int query(int node, int ini, int fim , int l, int r){
        if(l<= ini && fim <= r) return tree[node];
        if(ini > r || fim < l) return 0; 
        int mid = (ini+fim)/2;
        return query(2*node, ini, mid, l, r) + query(2*node+1, mid + 1, fim , l ,r );
    }



};

struct Query {
    int l, r, idx;
};

bool compare(const Query &a, const Query &b) {
    return a.r < b.r; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    
    int q; cin >> q; 
    vector<Query> queries(q); 
    for(int i=0;i<q;i++){
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i; 
    }

    sort(queries.begin(), queries.end(), compare); 
    
    vector<int> mapa(1e6+10); 
    vector<int> ans(n+1, 0);
    Seg seg(n);
    seg.build(1,1,n,ans);
    
    vector<int> final(q);

    int last_q = 0;
    for(int i=1;i<=n;i++){
        int val = v[i]; 
        if(mapa[val] == 0){
            mapa[val] = i;
            seg.update(1,1,n,i,1);
        } else { 
            int last = mapa[val];
            mapa[val] = i;
            seg.update(1,1,n,last,0);
            seg.update(1,1,n,i,1);
        }

        while(last_q < q && i == queries[last_q].r){
            
            int original_idx = queries[last_q].idx;
            int resposta_query = seg.query(1, 1, n, queries[last_q].l, queries[last_q].r);
            
            final[original_idx] = resposta_query; 
            
            last_q++;
        }
    }

    for(int i = 0; i < q; i++) {
        cout << final[i] << "\n";
    }
    
    return 0;
}