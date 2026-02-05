#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int N = 1e5+10;
const int B = 320;

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

// problem link: https://judge.yosupo.jp/problem/static_range_inversions_query


struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n+1, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int v[N];
int inv = 0; 
int n_comprimido;
vector<int> s;

struct Querie{
    int begin, end, idx; 
};  


bool cmp(Querie a, Querie b){
    if(a.begin / B < b.begin / B) return true; 
    if(a.begin / B > b.begin / B) return false; 
    return a.end < b.end;
}

void coordinate(int n){
    vector<int> tmp;
    for(int i=0;i<n;i++){
        tmp.push_back(v[i]);
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    s = tmp;

    for(int i=0;i<n;i++){
        v[i] = lower_bound(s.begin(), s.end(), v[i]) - s.begin();
    }
    n_comprimido = s.size();
}

void add_right(int idx, FenwickTree &bit){
    int val = v[idx];
    inv += bit.sum(val+1, n_comprimido);    
    bit.add(val,1);
}

void remove_right(int idx, FenwickTree &bit){
    int val = v[idx];
    bit.add(val, -1); 
    inv -= bit.sum(val + 1, n_comprimido);
}

void add_left(int idx, FenwickTree &bit){
    int val = v[idx];
    inv += bit.sum(0, val - 1);
    bit.add(val, 1);
}


void remove_left(int idx, FenwickTree &bit){
    int val = v[idx];
    bit.add(val, -1); 
    inv -= bit.sum(0, val - 1);
}



signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    for(int i=0;i<n;i++) {
        int num; cin >> num;
        v[i] = num;
    }
    coordinate(n);
    FenwickTree bit(n_comprimido + 5);

    vector<Querie> queries; 
    for(int i=0;i<q;i++){
        int a,b; cin >> a >> b; 
        queries.push_back({a,b-1,i});
    }
    sort(queries.begin(), queries.end(), cmp);
    vector<int> ans(q);
    int tl = 0, tr = -1;
    // a ideia é percorrer um vetor de quantidade do vetor de compressão de coordenadas
    for(auto [l,r,idx]:  queries){
        while(tr < r){
            tr++;
            add_right(tr,bit);
        }
        while(tl > l){
            tl--; 
            add_left(tl, bit);
        }
        while(tr > r){
            remove_right(tr, bit); 
            tr--;
        }
        while(tl < l){
            remove_left(tl,bit);
            tl++;
        }
       ans[idx] = inv;
    }
    for(int i=0;i<q;i++){
        cout << ans[i] << "\n";
    }
    return 0;
}