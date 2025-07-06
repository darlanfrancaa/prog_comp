#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll potencia(ll a, ll b, ll mod){
    ll ans = 1;
    a %= mod;
    while(b){
        if(b & 1) ans = (ans * a) % mod;
        a = (a*a) % mod;
        b /= 2;
    }
    return ans;
}
ll inv(ll a, ll mod){
    return a <= 1 ?  a : mod - mod/a * inv(mod % a, mod) % mod;
}



int main() {
    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    ll a,b; cin >> a >> b;
    if(b == 0) cout << "1" << endl;
    else{
        ll ans = 1;
        for(ll i=2;i*i<=a;i++){
            if(a % i == 0){
                ll contador = 0;
                while(a % i == 0){
                    contador++;
                    a/=i;
                }
                ll deno = inv((i-1+MOD) % MOD, MOD);
                ll num = (potencia(i, (contador * (b % (MOD - 1)) + 1) % (MOD - 1), MOD) - 1 + MOD) % MOD;
                ans = (ans * ((deno * num)% MOD)) % MOD;
            }
        }
        if(a > 1 && (a-1) % MOD != 0){
            ll deno = inv((a - 1 + MOD) % MOD, MOD);
            ll num = (potencia(a, (b + 1) % (MOD - 1), MOD) - 1 + MOD) % MOD;
            ans = (ans * ((deno * num)% MOD)) % MOD;
        } else if (a > 1){
            ans = (ans * ((b+1) % MOD)) % MOD;
        }
        cout << ans << endl;
    }
   
    return 0;
}