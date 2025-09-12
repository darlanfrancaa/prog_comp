#include <bits/stdc++.h>
using namespace std;

#define ll long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int LOG = 30;

ll solve(const vector<bool> &nums){
    int n = nums.size() - 1;
    vector<int> pref(n+1);
    ll contador_0 = 1, contador_1 = 0;
    pref[0] = 0;
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1] ^ nums[i];
        if(pref[i] == 1) contador_1++;
        else contador_0++;
    }
    int ret = 0;
    return contador_0 * contador_1;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    ll ans = 0;
    for(int i=LOG;i>=0;i--){
        vector<bool> nums(n+1);
        for(int j=1;j<=n;j++) {
            nums[j] = (v[j] & (1 << i));    
        }
        ans += (solve(nums) << i);
    }
    cout << ans << "\n";
    return 0;
}