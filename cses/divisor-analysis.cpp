#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll potencia(ll a, ll b, ll modulo){
    a %= modulo;
    ll ans = 1; 
    while (b > 0) {
        if(b % 2 == 1) ans = ans * a % modulo;
        a = a * a % modulo;
        b /= 2;
    } 
    return ans;
}

ll pot[100001];
ll expo[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> pot[i] >> expo[i];
    }
    ll contador_1 = 1, contador_2 = 1, soma = 1 , produto = 1;
    for(int i=0;i<n;i++){
        contador_1 = (contador_1) * (expo[i]+1) % MOD;
        soma = soma *
                (potencia(pot[i],expo[i]+1, MOD)-1) % MOD * potencia(pot[i]-1, MOD-2, MOD) % MOD;
        produto = potencia(produto, expo[i]+1, MOD) * 
                (potencia(potencia(pot[i],(expo[i] * (expo[i] +1) / 2), MOD), contador_2, MOD)) % MOD;
        contador_2 = contador_2 * (expo[i]+1) % (MOD-1);
    } 
    cout << contador_1 << " " << soma << " " << produto;
    return 0;
}