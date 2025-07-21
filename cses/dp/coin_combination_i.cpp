#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

vector<ll> dp;

void fill_dp(const vector<int>& moedas, int x){
    dp.assign(x+1,0);
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        for(auto moeda: moedas){
            if(i>= moeda && dp[i-moeda] != 0){
                dp[i] = (dp[i] + dp[i-moeda]) % MOD; 
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n >> x;
    vector<int> moedas(n);
    for(auto &moeda : moedas) cin >> moeda;
    fill_dp(moedas,x);
    cout << dp[x] << endl;
    return 0;
}