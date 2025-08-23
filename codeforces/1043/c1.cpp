#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        ll n; cin >> n; 
        ll contador = 0, pot = 1; 
        while (pot * 3 <= n) {
            pot *= 3;
            contador++;
        }
        ll ans = 0; 
        while(n > 0){
            if(n >= pot){ 
                n -= pot; 
                ans += 3*pot + contador * pot/3;
            } else { 
                pot /= 3;
                contador--;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}