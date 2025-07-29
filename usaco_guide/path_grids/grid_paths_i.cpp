#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<vector<char>> tab(n,vector<char>(n));
    for(int i= 0; i<n;i++){
        for( int j = 0; j<n;j++){
            cin >> tab[i][j];
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            if(tab[i][j] == '*') dp[i][j] = 0; 
            else {
                if(i>0) dp[i][j] += dp[i-1][j];
                if(j>0) dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n-1][n-1] << endl; 
    return 0;
}