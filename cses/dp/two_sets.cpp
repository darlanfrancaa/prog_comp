#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    ll mid_sum = n * (n+1) / 2; 
    if (mid_sum % 2 != 0) cout << 0 << endl; 
    
    else { 
        mid_sum /= 2; 
        vector<vector<int>> dp(n+1, vector<int>(mid_sum+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int sum = 1; sum<= mid_sum; sum++){
                dp[i][sum] += dp[i-1][sum];
                if(sum >= i){
                    dp[i][sum] = (dp[i][sum] + dp[i-1][sum-i]) % MOD;
                }
            }
        
        }
        cout << dp[n][mid_sum] << endl; 
    } 
    return 0;
}