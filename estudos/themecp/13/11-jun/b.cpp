#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link:https://codeforces.com/problemset/problem/1858/C

void solve(){
    int n; cin >> n;
    vector<int> ans; 
    int k = 1; 
    while(k <= n){
        int d = k; 
        while(d <= n){
            ans.push_back(d);
            d = 2 * d; 
        } 
        k += 2;
    }
    for(auto val: ans){
        cout << val << " ";
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