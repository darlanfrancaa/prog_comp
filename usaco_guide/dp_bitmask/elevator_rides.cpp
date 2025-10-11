#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; int x; cin >> n >> x; 
    int MAX_M = (1<<n);
    vector<int> v(n);
    for(auto &a: v) cin >> a;
    vector<pii> dp(MAX_M);
    dp[0] = {1,0};
    for(int mask = 1; mask < MAX_M ; mask++){
        dp[mask] = {n+1,0};
        for(int i=0;i<n;i++){
            if((mask >> i) & 1){
                int last = mask ^ (1 << i);
                pii last_ans = dp[last];

                if(last_ans.second + v[i] <= x){
                    pii par1 = {last_ans.first, last_ans.second + v[i]};
                    dp[mask] = min(dp[mask], par1);
                } else { 
                    pii par2 = {last_ans.first + 1, v[i]};
                    dp[mask] = min(dp[mask], par2);
                }
            }
        }
    }
    cout << dp[MAX_M-1].first << "\n";
    return 0;
}