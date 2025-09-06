#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k_original;
    cin >> n >> k_original;
    int k = min(k_original, (int)65); 
    vector<vector<int>> dp(66, vector<int>(k + 1, 0)); // dp[t][k] é o máximo N que pode ser encontrado com t testes e k balões
    for (int t = 1; t <= 65; t++) {
    
        for (int bk = 1; bk <= k; bk++) {
            dp[t][bk] = 1 + dp[t - 1][bk - 1] + dp[t - 1][bk];
        }
        if (dp[t][k] >= n) {
            cout << t << "\n"; 
            return 0;          
        }
    }

    return 0;
}