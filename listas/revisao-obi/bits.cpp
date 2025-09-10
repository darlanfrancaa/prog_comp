#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int power(int a, int b){
    a %= MOD;
    int res = 1; 
    while(b > 0){
        if(b % 2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    if (n < k) {
        cout << power(2, n) << "\n";
        return 0; 
    }

    vector<int> dp(n + 1, 0);

    for(int i = 0; i < k; i++){
        dp[i] = power(2, i);
    }
    dp[k] = (power(2, k) - 1 + MOD) % MOD;
    
    for(int i = k + 1; i <= n; i++){
        dp[i] = (2 * dp[i-1] - dp[i-k-1] + MOD) % MOD;
    }
    
    cout << dp[n] << "\n";

    return 0;
}