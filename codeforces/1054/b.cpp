#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n; 
    vector<int> v(n);
    for(auto &a: v) cin >> a; 
    sort(v.begin(), v.end());
    int maximo = INT_MIN;
    for(int i=0;i<n-1;i+=2){
        int diff = v[i+1]-v[i];
        maximo = max(maximo, diff);
    }
    cout << maximo << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}