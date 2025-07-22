#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        
        vector<int> fila(n);
        for(auto &boss:fila) cin >> boss; 
        if (n == 1) {
            cout << fila[0] << endl;
            continue;
        }
        if (n == 2) {
            if(fila[0] == 1 && fila[1] == 1) cout << 1 << endl;
            else if(fila[0] == 1 && fila[1] == 0) cout << 1 << endl;
            else if(fila[0] == 0) cout << 0 << endl;
            continue;
        }
        vector<vector<int>> dp(n,vector<int>(2,INT_MAX));
        dp[n-1][1] = 0; dp[n-1][0] = fila[n-1];
        dp[n-2][1] = 0;
        dp[n-2][0] = min(dp[n-1][1] + fila[n-2], fila[n-1]+fila[n-2]);
        for(int i=n-3;i>=0;i--){
            dp[i][1] = min(dp[i+1][0], dp[i+2][0]);
            dp[i][0] = min(dp[i+1][1] + fila[i], dp[i+2][1] + fila[i]+fila[i+1]);
        }
        cout << dp[0][0] << endl;

    }
    return 0;
}