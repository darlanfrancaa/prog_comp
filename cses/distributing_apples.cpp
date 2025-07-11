#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 1; 
/*Se eu quero distribuir as m maças para n crianças, então eu posso tentar distribuir as n crianças
para as m macas ou seja achar o numero de solucoes de
x_1 +x _2  + ... + x_n = m, que é m + n -1 escolhe n  */

ll fat[MAXN+1];
ll inv[MAXN+1];

ll exp(ll a, ll b){
    a %= MOD;
    ll ret = 1; 
    while(b > 0){
        if(b % 2 == 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ret;
}

void fatorial(int n){
    fat[0] = 1;
    for(int i=1;i<=n;i++){
        fat[i] = i * fat[i-1] % MOD;
    }
}

void inversos(int n){
    inv[n] = exp(fat[n], MOD-2);
    for(int i=n;i>=1;i--){
        inv[i-1] = inv[i] * i % MOD;
    }
}

ll binomial(int m,int n){
    return fat[m] * inv[n] % MOD * inv[m-n] % MOD;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    fatorial(m+n);
    inversos(m+n);
    cout << binomial(n+m-1, m);
    return 0;
}