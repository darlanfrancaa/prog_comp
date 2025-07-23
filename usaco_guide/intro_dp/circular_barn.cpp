#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k; 
    deque<int> fenos(n,0);
    for(auto &feno: fenos) cin >> feno; 
    ll min_dist = INT64_MAX;

    for(int comeco= 0; comeco< n; ++comeco){
        vector<vector<ll>> dp(k+1,vector<ll>(n+1,INT64_MAX));
        dp[0][0] = 0;
        for(int i=1; i<=k;i++){
            for(int j=1; j<=n;j++){
                ll custo_segmento = 0;
                ll soma_vacas = 0;
                for(int p = j-1;p>=0;p--){
                    custo_segmento += soma_vacas;
                    soma_vacas += fenos[p];

                    if(dp[i-1][p] != INT64_MAX){
                        dp[i][j] = min(dp[i][j], dp[i-1][p] + custo_segmento);
                    }
                }
            }
        }
        min_dist = min(min_dist, dp[k][n]);
        int prox_comeco = fenos.front(); fenos.pop_front();
        fenos.push_back(prox_comeco);
    }
    
    cout << min_dist << endl; 
    
    return 0;
}