#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string pal1, pal2; cin >> pal1 >> pal2;
    int n = pal1.size();
    int m = pal2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1, INT_MAX));
    dp[0][0] = 0; 
    for(int i=0;i <= n;i++){
        for(int j=0;j<= m;j++){
            if(i!= 0){
                dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            }
            if(j!= 0){
                dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            }
            if(i!= 0 && j != 0){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (pal1[i-1] != pal2[j-1]));
            }
        }
    }
    cout << dp[n][m] << endl;

    return 0;
}