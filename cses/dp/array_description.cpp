#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> valores(n);
    for(auto &valor: valores) cin >> valor;
    vector<vector<ll>> dp(n,vector<ll>(m+2,0));
    if (valores[0] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 1;
        }
    } else dp[0][valores[0]] = 1;
    for (int i = 1; i < n; i++) {
        if (valores[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
            }
        } else {
            int x = valores[i];
            dp[i][x] = (dp[i - 1][x - 1] + dp[i - 1][x] + dp[i - 1][x + 1]) % MOD;
        }
    }
    ll ans = 0;
    for(int j=1; j<=m;j++) ans = (ans + dp[n-1][j]) % MOD;
    cout << ans << endl;
    return 0;
}