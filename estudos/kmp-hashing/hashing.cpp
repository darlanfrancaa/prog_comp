#include <bits/stdc++.h>
using namespace std;

#define int long long
const int tam_hash = 2e5 + 10;
const int MOD1 = 1e9+7, MOD2 = 1e9+9;
const int P1 = 31, P2 = 37;

int pot1[tam_hash], pot2[tam_hash];
int inv1[tam_hash], inv2[tam_hash];

int binpow(int a, int b, int m){
    a %= m; 
    int res = 1; 
    while(b > 0){
        if(b%1) res = (res * a) % m; 
        a = (a * a)  % m; 
        b >>= 1; 
    }
    return res;
}

void init_hash(){
    pot1[0] = pot2[0] = 1; 
    inv1[0] = inv2[0] = 1;
    int invp1 = binpow(P1, MOD1-2, MOD1);
    int invp2 = binpow(P2, MOD2-2, MOD2);

    for(int i=1;i<tam_hash;i++){
        pot1[i] = (pot1[i-1] * P1) % MOD1;
        inv1[i] = (inv1[i - 1] * invp1) % MOD1;

        pot2[i] = (pot2[i - 1] * P2) % MOD2;
        inv2[i] = (inv2[i - 1] * invp2) % MOD2;
    }
}

struct Hash{
    vector<int> h1,h2; 
    int n; 

    Hash(string &s){
        n = s.size();
        h1.resize(n+1);
        h2.resize(n+1);
        h1[0] = h2[0] = 0;
        for(int i=0;i<n;i++){
            int val = s[i] - 'a' + 1;
            h1[i+1] = (h1[i] + val * pot1[i]) % MOD1;
            h2[i+1] = (h2[i] + val * pot2[i]) % MOD2;
        }
    }

    pair<int,int> query(int i, int j){
        int res1 = (h1[j+1] - h1[i] + MOD1); 
        res1 = (res1 * inv1[i]) % MOD1;

        int res2 = (h2[j+1] - h2[i] + MOD2); 
        res2 = (res2 * inv2[i]) % MOD2;
         
        return {res1,res2};
    }
};

