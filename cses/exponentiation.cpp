#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

long long potencia(ll a, ll b){
    if(b==0) return 1;
    if(b%2 == 1){
        return ((potencia(a,b-1) % MOD)* (a % MOD)) % MOD;
    }
    else{
        long long valor_mod = potencia(a,(b/2)) % MOD;
        return (valor_mod * valor_mod) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        ll a, b; cin >> a >> b;
        cout << potencia(a,b) << endl;
    }
    return 0;
}