#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

/*link do problema https://cses.fi/problemset/task/2185*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n; cin >> n;
    int k; cin >> k;
    vector<long long> primos(k);
    for(auto &primo:primos) cin >> primo;
    long long sum = 0;
    for(int i = 1;i<(1<<k);i++){
        int num = i; 
        long long prod = 1;
        int contador = 0;
        int contador_1 = 0;
        while(num > 0){
            if((num & 1 ) == 1) {
                if(primos[contador] > n/prod){
                    prod = n+1;
                    break;
                }
                prod *= primos[contador];
                contador_1++;
            }
            contador++;
            num >>= 1;
        }
        sum += (contador_1 % 2 == 1) ? (n/prod) : -(n/prod);

    }
    cout << sum << endl;
    return 0;
}