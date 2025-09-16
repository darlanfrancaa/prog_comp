#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAX = 105;
int dp[MAX][MAX][MAX];

//link: https://atcoder.jp/contests/abc281/tasks/abc281_d?lang=en

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k,d; cin >> n >> k >> d;
    vector<int> nums(n+1);
    for(int i=1;i<=n;i++) cin >> nums[i];
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int l = 0; l < d; l++){
                dp[i][j][l] = dp[i-1][j][l];
                if(j > 0){
                    int resto = (l - (nums[i] % d) + d) % d;
                    if(dp[i-1][j-1][resto] != -1){
                        dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][resto] + nums[i]);
                    }
                }
            }
        }
    }
    cout << dp[n][k][0];
    return 0;
}