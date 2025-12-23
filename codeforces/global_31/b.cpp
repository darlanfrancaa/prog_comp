#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<string> pal(n); 
    for(auto &s: pal) cin >> s;
    string ans = "";
    for(int i=0;i<n;i++){
        string ans1 = ans + pal[i]; 
        string ans2 = pal[i] + ans;
        ans = min(ans1, ans2);
    } 
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}