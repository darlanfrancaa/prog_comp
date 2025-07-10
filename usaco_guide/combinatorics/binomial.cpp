#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 1;

ll fat[MAXN+1];
ll inv[MAXN+1];

ll exp(ll x, ll n, ll m){
    x %= m;
    ll ans = 1;
    while(n>0){
        if(n % 2 == 1) ans = ans * x % m;
        x = x * x % m;
        n /= 2;
    }
    return ans;
}

void fatorial(ll p){
    fat[0] = 1;
    for(int i=1;i<=MAXN;i++){
        fat[i] = fat[i-1] * i % p;
    }
}

void inversos(ll p){
    inv[MAXN] = exp(fat[MAXN], p-2, p);
    for (int i = MAXN; i>= 1;i--) {
        inv[i-1] = inv[i] * i % p;
    }
}

ll binomial(ll n, ll k, ll p){
    return fat[n] * inv[k] % p * inv[n-k] % p;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fatorial(MOD);
    inversos(MOD);
    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b; 
        cout << binomial(a,b,MOD) << endl;
    }
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}