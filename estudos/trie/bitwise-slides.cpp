#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/blog/entry/139415
void solve(){
    int n; cin >> n;
    vector<int> v(n);
    vector<int> pref(n+1, 0);
    vector<int> vals;
    vals.push_back(0);
    for(int i=0;i<n;i++){
        cin >> v[i];
        pref[i+1] = pref[i] ^ v[i];
        vals.push_back(pref[i+1]);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    auto get_id = [&](int x) {
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    };

    int ans = 1;
    vector<int> dp(vals.size(),  0);
    dp[get_id(0)] = 1;
    
    int curr_pref = 0; 
    for(int i=0;i<n;i++){
        int curr_id = get_id(pref[i]);
        int next_id = get_id(pref[i+1]);
        
        int last_dp_curr = dp[curr_id];
        int last_dp_next = dp[next_id];
        
        int new_dp_curr = (3LL * last_dp_curr + 2LL * last_dp_next) % MOD;
        ans = (ans - last_dp_curr + new_dp_curr + MOD) % MOD;
        
        dp[curr_id] = new_dp_curr; 
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