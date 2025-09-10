#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// link : https://atcoder.jp/contests/abc229/tasks/abc229_c

bool compare(pii &a, pii &b){
    return a.first > b.first;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, w; cin >> n >> w; 
    int<pii> v(n);
    for(auto &a: v) cin >> a.first >> a.second;
    sort(v.begin(), v.end(), compare);
    int soma = 0; 
    for(int i = 0; i < n; i++){
        if(w == 0) break;
        if(w >= v[i].second){
            w -= v[i].second;
            soma += v[i].second * v[i].first;
        } else if ( w < v[i].second){
            soma += w * v[i].first;
            w = 0;
        }
    }
    cout << soma << "\n";
    return 0;
}