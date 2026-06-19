#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int fast_pow(int a, int b){
    int ret = 1; 
    a = a%MOD;
    while(b > 0){
        if(b & 1) ret = (ret * a)% MOD;
        a = (a * a) % MOD; 
        b = b/2;
    }

    return ret % MOD;
}

int inv(int x){
    x = (x%MOD);
    int ret = fast_pow(x, MOD-2);
    return ret % MOD;
}

void solve(){
    int n, m ,k; 
    cin >> n >> m >> k;
    int prob_branco = fast_pow((((m*n - 1) % MOD) * inv(m*n)) % MOD, k) % MOD;
    int prob_preto = (1 - prob_branco + MOD) % MOD;
    int contada_dentro = 2 * ((m*n) % MOD) * inv(m*n)
    int qntd_borda = (2*m + 2*n) % MOD;
    int qntd_dentro = (2*m*n - m - n) % MOD;
    int resp = (((qntd_dentro * contada_dentro) % MOD) + ((qntd_borda * prob_preto) % MOD)) % MOD;
    cout << resp % MOD << "     "  << prob_branco << "      " << prob_preto << "    ";

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}