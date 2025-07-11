#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 1;
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



int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    string pal; cin >> pal; 
    int tam = pal.size();
    fatorial(tam); inversos(tam);
    map<char,int> mapa;
    for(int i=0;i<tam;i++){
        mapa[pal[i]]++;
    }
    ll ans = fat[tam];
    for(auto [k,v]: mapa){
        ans = ans * inv[v] % MOD;
    }
    cout << ans << endl;
    return 0;
}