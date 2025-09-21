#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 21;

int dp[MAXN+2][1<<MAXN];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            int b; cin >> b; 
            if(b) adj[i].push_back(j);
        }
    }
    dp[0][0] = 1;
    
    for(int i=1;i<=n;i++){
        for(int mask = 1; mask < (1<<n); mask++){
            if(__builtin_popcount(mask) != i) continue;
            for(auto v: adj[i]){
                if((mask & (1<<v))) dp[i][mask] = (dp[i][mask] + dp[i-1][mask ^ (1 << v)]) % MOD;
            }
        }
    }
    cout << dp[n][(1<<n) - 1];
    return 0;
}