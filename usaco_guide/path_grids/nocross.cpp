#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> left(n+1,0); 
    vector<int> right(n+1, 0);
    for(int i=1;i<=n;i++) cin >> left[i];
    for(int i=1;i<=n;i++) cin >> right[i];
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            bool aresta = abs(left[i]-right[j]) <= 4;
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + aresta);
        }
    }
    cout << dp[n][n] << endl;

    return 0;
}