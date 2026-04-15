#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1647


const int N = 2e5 + 10;
int v[N];
int ans[N]; 

struct Query {
    int l, r, id;
};

void solve(int l, int r, vector<Query> &queries){
    if(queries.empty()) return;
    if(l == r){
        for(auto& q: queries){
            ans[q.id] = v[l];
        }
        return;
    }
    int mid = (l+r)/2;
    vector<Query> left_q, right_q, meio_q;
    for(auto& q: queries){
        if(q.r <= mid){
            left_q.push_back(q);
        } else if(q.l > mid){
            right_q.push_back(q);
        } else {
            meio_q.push_back(q);
        }
    }

    if (!meio_q.empty()) {
        vector<int> min_val(r + 1);
        

        int cur_min = v[mid];
        for (int i = mid; i >= l; i--) {
            cur_min = min(cur_min, v[i]);
            min_val[i] = cur_min;
        }
        
        cur_min = v[mid + 1];
        for (int i = mid + 1; i <= r; i++) {
            cur_min = min(cur_min, v[i]);
            min_val[i] = cur_min;
        }
        
        for (auto& q : meio_q) {
            ans[q.id] = min(min_val[q.l], min_val[q.r]);
        }
    }

    solve(l, mid, left_q);
    solve(mid + 1, r, right_q);
}

signed main() {
    int n, q; 
    cin >> n >> q; 
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    vector<Query> queries;
    for (int i = 0; i < q; i++) {
        int l, r; 
        cin >> l >> r;
        queries.push_back({l, r, i}); 
    }
    
    solve(1, n, queries);
    
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}