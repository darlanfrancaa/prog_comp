#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/2222/D

bool cmp(pii &a, pii &b){
    return a.second < b.second;
}

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &val: v) cin >> val; 
    vector<pii> pref(n); // {idx, pref}
    pref[0] = {1,0};
    for(int i=1;i<n;i++){
        int acc = pref[i-1].second + v[i-1]; // pref[n-1] = pref[n-2] + v[n-2]
        pref[i] = {i+1, acc};        
    }
    sort(pref.begin(), pref.end(), cmp);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        ans[pref[i].first-1] = n-i;
    }    
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}