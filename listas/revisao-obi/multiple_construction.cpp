#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    for(int i=n;i>=1;--i) cout << i << " ";
    cout << n << " ";
    for(int i=1;i<=n-1;i++) cout << i << " ";
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