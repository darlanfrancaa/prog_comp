#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link : https://atcoder.jp/contests/dp/tasks/dp_c

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    int<int<int>> v(n+1,int<int> (3));
    for(int i=1;i<=n;i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    int<int<int>> dp(n+2,int<int> (3,0));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            dp[i][j] = max(dp[i][j], dp[i-1][(j+1) % 3] + v[i][j]);
            dp[i][j] = max(dp[i][j], dp[i-1][(j+2) % 3] + v[i][j]);
        }
    }
    int<int> fim;
    for(int i=0;i<3;i++){
        fim.push_back(dp[n][i]);
    }
    sort(fim.begin(), fim.end());
    cout << fim[2] << "\n";

    return 0;
}