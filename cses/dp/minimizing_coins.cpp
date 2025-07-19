#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
vector<int> dp;

void fill_dp(const vector<int> &moedas, int x){
    dp.assign(x+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=x;i++){
        for(auto moeda: moedas){
            if(i >= moeda){
                if(dp[i-moeda] != INT_MAX){
                    dp[i] = min(dp[i - moeda] + 1, dp[i]);
                }
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n >> x;
    vector<int> moedas(n);
    for(auto &moeda: moedas) cin >> moeda;
    fill_dp(moedas, x);
    if(dp[x] == INT_MAX) cout << -1 << endl;
    else cout << dp[x] << endl;
    return 0;
}