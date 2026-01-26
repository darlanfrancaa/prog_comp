#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1734

class SegTree{
private: 
    int n; 
    vector<int> tree; 
public:

    void build(int node, int l, int r, vector<int> &v){
        if(l == r) {
            tree[node] = v[l];
            return; 
        }
        int mid = (l+r)/2; 
        build(2*node, l, mid, v);
        build(2*node+1, mid+1, r, v);
        tree[node] = tree[2*node] + tree[2*node+1];
        return;
    }

    SegTree(int n, vector<int> &v){
        tree.resize(4*n);
        build(1,0,n-1,v);
    }

    void update(int node, int l, int r, int pos, int val){
        if(l == r) {
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
        if(begin > r || end < l ) return 0; 
        if(l <= begin && end <= r) return tree[node]; 
        int mid = (begin+end)/2; 
        int j1 = query(2*node, begin, mid, l , r); 
        int j2 = query(2*node+1, mid+1, end, l , r); 
        return j1+ j2;
    } 
};

bool compare(pii a, pii b){
    if(a.second < b.second) return true; 
    return false;
}


struct Query{
    int begin, end, idx;
};

struct CompareQuery{
    bool operator()(const Query a, const Query b){
        if(a.end != b.end) {
            return a.end < b.end; 
        }
        return a.begin < b.begin;
    }
};

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    vector<int> v(n); 
    for(int i=0;i<n;i++){   
        cin >> v[i];
    }
    map<int,int> last_pos;
    vector<Query> queries; 
    for(int i=0;i<q;i++){
        int a, b; cin >> a >> b; 
        a--;b--;
        queries.push_back({a,b,i});
    }
    sort(queries.begin(), queries.end(), CompareQuery());
    vector<int> dist(n,0);
    SegTree seg(n,dist);
    int curr_query = 0;
    vector<int> ans_queries(q);
    for(int i=0;i<n;i++){
        int val = v[i];
        // printf("o valor atual para i = %lld é %lld\n", i, val);
        if (last_pos.count(val)) {
            int prev_index = last_pos[val];
            seg.update(1, 0, n - 1, prev_index, 0); 
        }
        seg.update(1, 0, n - 1, i, 1); 
        last_pos[val] = i; 

        // printf("para i = %lld, temos as seguintes queries:\n", i);
        while(curr_query < queries.size() && queries[curr_query].end == i){
            auto [begin,end,idx] = queries[curr_query];
            // printf("a queries [%lld, %lld] foi resolvida\n", begin, end);
            ans_queries[idx] = seg.query(1,0,n-1,begin,end);
            curr_query++;
        }
    }

    for(int i=0;i<q;i++){
        cout << ans_queries[i] << "\n";
    }

    return 0;
}