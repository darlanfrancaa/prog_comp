#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
const int MAXN = 5000;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int q, k; cin >> q >> k; 
    vector<ll> dp(k+1);
    dp[0] = 1; 

    for(int i = 0;i < q; i++){
        char op; int x; cin >> op >> x;
        if ( op == '+') {
            for(int j = k; j>= x; j--) dp[j] = (dp[j] + dp[j-x]) % MOD;
        } else {
            for(int j = x; j<= k;j++) dp[j] = (dp[j] + MOD - dp[j-x]) % MOD;
        }
        cout << dp[k] << endl;
    }

    
    
    return 0;
}