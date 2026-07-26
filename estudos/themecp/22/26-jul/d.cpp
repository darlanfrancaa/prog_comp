#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: 

const int N = 3e5 + 10;
int dp[N];

void pre_calc(){
    dp[0] = 1; 
    dp[1] = 1; 
    for(int i=2;i<N;i++){
        dp[i] = (2 * dp[i-2] * (i-1)) % MOD;
        dp[i] = (dp[i] + dp[i-1]) % MOD;
    }
}

void solve(){
    int n, k; cin >> n >> k; 
    int qtd = n; 
    while(k--){
        int a,b; cin >> a >> b; 
        if(a == b) qtd -= 1; 
        else qtd -= 2; 
    }
    cout << dp[qtd] << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    pre_calc();
    while(t--){
        solve();
    }
    return 0;
}