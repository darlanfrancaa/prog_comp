#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

// #define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int N = 2e5+10; 
const int B = 500;
const int MAX_BLOCOS = N/B + 5;
// problem link: https://oj.uz/problem/view/JOI19_examination


struct Queries{
    int x; 
    int y; 
    int z; 
    int idx;

    bool operator<(const Queries &a) const {
        return x > a.x;
    }
};

bool cmp(pii a, pii b){
    return a.first > b.first;
}

class Sqrt{
private: 
    vector<int> bloco[MAX_BLOCOS];
    vector<pii> bloco_completo[MAX_BLOCOS];
public: 
    void add(int b, int soma){
        int idx_bloco = b/B;
        bloco_completo[idx_bloco].push_back({b,soma});
        
        auto &vec = bloco[idx_bloco];
        auto it = upper_bound(vec.begin(), vec.end(), soma);
        vec.insert(it, soma);
    }

    int query(int y_idx, int z){
        int total = 0;
        int idx_bloco = y_idx / B;

        for(auto &p : bloco_completo[idx_bloco]){
            if(p.first >= y_idx && p.second >= z) total++;
        }

        for(int i = idx_bloco + 1; i < MAX_BLOCOS; i++){
            if(bloco[i].empty()) continue; 
            total += (bloco[i].end() - lower_bound(bloco[i].begin(), bloco[i].end(), z));
        }

        return total;
    }

};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q; cin >> n >> q; 
    vector<pii> pares(n); 
    vector<int> coord;
    for(int i=0;i<n;i++){
        cin >> pares[i].first >> pares[i].second;
        coord.push_back(pares[i].second);
    }
    vector<Queries> queries(q);
    for(int i=0;i<q;i++){
        cin >> queries[i].x >> queries[i].y >> queries[i].z;
        queries[i].idx = i;
        coord.push_back(queries[i].y);
    }
    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());
    auto get_idx = [&](int val) {
        return lower_bound(coord.begin(), coord.end(), val) - coord.begin();
    };
    sort(pares.begin(), pares.end(), cmp);
    sort(queries.begin(), queries.end());

    Sqrt sq; 
    vector<int> ans(q);
    int ptr = 0;
    for(int i=0;i<q;i++){
        while(ptr < n && pares[ptr].first >= queries[i].x){
            int b_comp = get_idx(pares[ptr].second);
            sq.add(b_comp, pares[ptr].first + pares[ptr].second);
            ptr++;
        }
        int y_comp = get_idx(queries[i].y);
        ans[queries[i].idx] = sq.query(y_comp, queries[i].z); 
    }

    for(int i=0;i<q;i++){
        cout << ans[i] << "\n";
    }
    return 0;
}