#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
int dp[1 << 20][21];

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    vector<string> s(m);
    for(int i=0;i<m;i++){
        cin >> s[i];
    }
    vector<int> a(1 << m, 0);
    for(int j=0;j<n;j++){
        int mask = 0;
        for(int i =0;i<m;i++){
            if(s[i][j] == 'H') mask |= (1 << i);
        }
        a[mask]++;
    }

    vector<int> comb(n+1,0);
    for(int c=1;c<=n;c++){
        comb[c] = (c * (1LL + comb[c-1])) % MOD;
    }
    int ans = 0; 

    for(int mask = 0;mask < (1 << m); mask++){
        dp[mask][0] = 0;
        for(int i=1;i<=m;i++){
            dp[mask][i] = dp[mask][i-1];
            if((mask >> (i-1)) & 1LL){
                int prev_mask = mask ^(1 << (i-1));
                dp[mask][i]  = (dp[mask][i] + dp[prev_mask][i-1]) % MOD;
            }
        }

        int t = dp[mask][m];
        int qnt = comb[a[mask]];
        int total = (qnt * (1LL + t)) % MOD;

        for(int i=0;i<=m;i++){
            dp[mask][i] = (dp[mask][i] + total) % MOD;
        }

        ans = (ans + total) % MOD;
    }

    cout << ans << "\n";

    return 0;
}