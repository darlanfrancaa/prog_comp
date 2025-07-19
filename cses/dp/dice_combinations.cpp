#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
vector<ll> dp;

void vetor(int n){
    dp.assign(n+1,0);
    for(int k=1;k<=6;k++){
        dp[k] = pow(2,k-1);
    }
    if(n>6){
        for(int k=7;k<=n;k++){
            for(int j=1;j<=6;j++){
                dp[k] = (dp[k] + dp[k-j]) % MOD;
            }
        }
    }
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vetor(n);
    cout << dp[n];
    return 0;
}