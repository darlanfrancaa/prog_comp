#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 600;

int dp[MAXN+1][MAXN+1];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int w,h; cin >> w >> h;
    int n; cin >> n;
    vector<pii> retangulos(n);
    for(auto &retangulo:retangulos) cin >> retangulo.first >> retangulo.second;
    for(int i=1;i<=w;i++)
        for(int j=1;j<=h;j++){
            dp[i][j] = i*j;
        }
    for(int i=0;i<n;i++){
        dp[retangulos[i].first][retangulos[i].second] = 0;
    }

    for(int i=1;i<=w;i++)
        for(int j=1;j<=h;j++){
            for(int x = 1;x <= i;x++) dp[i][j] = min(dp[i][j], dp[i-x][j] + dp[x][j]);
            for(int y = 1;y<= j; y++) dp[i][j] = min(dp[i][j], dp[i][j-y] + dp[i][y]);           
        }
    
    cout << dp[w][h] << endl;

    return 0;
}