#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> precos(n);
    for(auto &preco: precos) cin >> preco;
    vector<int> paginas(n);
    for(auto &pagina: paginas) cin >> pagina; 
    vector<vector<int>> dp(n+1, vector<int>(k+1,0));
    //de modo que dp[n][k] seja de quantos modos podemos escolher somar k tal que sejam usados apenas valores valores a[i] com i menor ou igual a n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= precos[i-1]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-precos[i-1]] + paginas[i-1]);
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}