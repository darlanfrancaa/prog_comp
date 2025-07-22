#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> grupos(n+1);
    for(int i=1;i<=n;i++) cin >> grupos[i]; 
    vector<vector<int>> dp(n+1,vector<int>(k+1,INT_MAX));
    int maximo_para_i = 0;
    int soma_total = 0;
    for(int i=1;i<=n;i++){
        maximo_para_i = max(maximo_para_i, grupos[i]);
        soma_total += grupos[i];
        dp[i][0] = i * maximo_para_i;
    }
    for(int i = 0; i <= k; i++) dp[0][i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            int tamanho = grupos[i];
            for(int c=i-1;c>=0;c--){
                dp[i][j] = min(dp[i][j], dp[c][j-1] + tamanho * (i-c));
                tamanho = max(tamanho, grupos[c]);
            }
        }
    }
    cout << dp[n][k] - soma_total << endl;
    return 0;
}