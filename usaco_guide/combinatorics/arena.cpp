#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;

ll exp(ll a, ll b){
    a %= MOD;
    ll ret = 1; 
    while(b > 0){
        if(b%2 == 1) ret = ret * a % MOD;
        a = a * a % MOD; 
        b /= 2;
    }
    return ret;
}

ll inverso(ll n){
    return exp(n, MOD-2);
}

vector<ll> fatorial;
vector<ll> inv_fatorial;

void preencher_fatorial(int max_n){
    fatorial.resize(max_n+1);
    inv_fatorial.resize(max_n+1);
    fatorial[0] = 1;
    for(int i=1;i<=max_n;i++){
        fatorial[i] = fatorial[i-1] * i %  MOD;
    }
    inv_fatorial[max_n] = inverso(fatorial[max_n]);
    for(int i = max_n;i>0;i--){
        inv_fatorial[i-1] = inv_fatorial[i] * (i) % MOD;
    }
}

ll binomial(int m, int n){
    if (n < 0 || n > m) {
        return 0;
    }
    return fatorial[m] * inv_fatorial[m-n] % MOD * inv_fatorial[n] % MOD;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n >> x; 
    preencher_fatorial(n);
    vector<vector<ll>> dp(x+1, vector<ll>(n+1,0));
    for(int i=0;i<=x;i++){
        dp[i][0] = 1;
    }
    for(int j=2;j<=n;j++){
        for(int i=1;i <= x; i++){
            if(i<j){
                dp[i][j] = exp(i,j);
            } else {
                ll atual_ans = 0;
                for(int k =0;k <= j ;k++){
                    if(k==1) continue;
                    ll comb = binomial(j,k);
                    ll caras_mortos = exp(j-1,j-k);
                    ll anterior = dp[i-j+1][k];

                    atual_ans = (atual_ans + ((anterior * comb % MOD) * caras_mortos % MOD)) % MOD;
                }
                dp[i][j] = atual_ans;
            }
        }
    }
    cout << dp[x][n] << endl;
    return 0;
}