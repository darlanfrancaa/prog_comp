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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        ll valor1 = potencia(b,c,MOD-1);
        ll valor2 = potencia(a,valor1, MOD);
        cout << valor2 << endl;
    }
    return 0;
}