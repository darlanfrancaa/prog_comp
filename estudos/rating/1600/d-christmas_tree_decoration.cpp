#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 998244353;

// problem link: https://codeforces.com/problemset/problem/2182/D

int dp[51];

void fill(){
    dp[0] = 1; 
    for(int i=1;i<=50;i++){
        dp[i] = (dp[i-1] * i) % MOD;
    }
}

int fast_pow(int a, int b){
    a %= MOD; 
    int ret = 1;
    while(b > 0){
        if(b & 1) ret = (ret * a) % MOD;
        a = (a*a) % MOD;
        b >>= 1;
    }
    return ret % MOD;
}

int inv(int num){
    return fast_pow(num, MOD-2);
}

void solve(){
    int n; cin >> n; 
    vector<int> v(n+1);
    int maximo = 0, qntd_max = 0;
    cin >> v[0];
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(v[i] > maximo){
            maximo = v[i]; 
            qntd_max = 1;
        } else if(v[i] == maximo) qntd_max++;
    }
    int sum_final = 0;
    for(int i=1;i<=n;i++){
        if(v[i] != maximo) sum_final += (maximo - v[i]-1);
    }
    int r_final = v[0] - sum_final;
    if(r_final < 0){
        cout << 0 << endl; 
        return;
    } else if (r_final >= n - qntd_max) {
        // isso quer dizer que cada um dos que não é maximo( n - qntd) pode retirar a vontade
        cout << dp[n] << endl; 
        return;
    } else { 
        int rest = qntd_max + r_final;
        int ans = dp[rest] * inv(dp[rest-qntd_max]); ans %= MOD;
        ans = (ans * dp[n-qntd_max]) % MOD; 
        cout << ans << endl; 
        return;
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    fill();
    while(t--){
        solve();
    }
    return 0;
}