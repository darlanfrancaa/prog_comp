#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://dmoj.ca/problem/ccc20s3
const int MAXN = 2e5+10;

const long long MOD1 = 1e9 + 7;
const long long P1 = 31;
const long long MOD2 = 1e9 + 9;
const long long P2 = 37;

long long pot1[MAXN], inv1[MAXN];
long long pot2[MAXN], inv2[MAXN];

long long binpow(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void precompute() {
    pot1[0] = 1; inv1[0] = 1;
    pot2[0] = 1; inv2[0] = 1;
    
    long long invP1 = binpow(P1, MOD1 - 2, MOD1);
    long long invP2 = binpow(P2, MOD2 - 2, MOD2);

    for (int i = 1; i < MAXN; i++) {
        pot1[i] = (pot1[i - 1] * P1) % MOD1;
        inv1[i] = (inv1[i - 1] * invP1) % MOD1;
        
        pot2[i] = (pot2[i - 1] * P2) % MOD2;
        inv2[i] = (inv2[i - 1] * invP2) % MOD2;
    }
}

struct Hash {
    vector<long long> h1, h2;
    
    Hash(string &s) {
        int n = s.size();
        h1.resize(n + 1, 0);
        h2.resize(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            int val = s[i] - 'a' + 1;
            h1[i + 1] = (h1[i] + val * pot1[i]) % MOD1;
            h2[i + 1] = (h2[i] + val * pot2[i]) % MOD2;
        }
    }

    pair<long long, long long> get(int l, int r) {
        long long v1 = (h1[r + 1] - h1[l] + MOD1) % MOD1;
        v1 = (v1 * inv1[l]) % MOD1;
        
        long long v2 = (h2[r + 1] - h2[l] + MOD2) % MOD2;
        v2 = (v2 * inv2[l]) % MOD2;
        
        return {v1, v2};
    }
};

int mapa_menor[26], mapa_maior[26];

bool check_igual() {
    for (int i = 0; i < 26; i++) {
        if (mapa_menor[i] != mapa_maior[i]) return false;
    }
    return true;
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    string menor, maior; cin >> menor >> maior;
    int n = menor.size();
    int m = maior.size();
    if(n > m){
        cout << 0 << "\n";
        return 0;
    }
    for(int i =0;i<n;i++){
        int l_menor = menor[i] - 'a';
        int l_maior = maior[i] - 'a';
        mapa_menor[l_menor]++;
        mapa_maior[l_maior]++;
        // printf("apareceu uma letra de valor %lld e eu coloquei no mapa, fazendo com que essa letra tenha um mapa de %lld\n", l_menor)
    }

    // for(auto [k,v]: mapa_menor){
    //     printf("para a chave %lld eu tenho o valor %lld\n", k, v);
    // }
    // for(auto [k,v]: mapa_maior){
    //     printf("para a chave %lld eu tenho o valor %lld\n", k, v);
    // }

    set<pair<int,int>> hash_perm;
    precompute(); 
    Hash h(maior);
    if(check_igual()) hash_perm.insert(h.get(0,n-1));

    for(int i = n; i<m;i++){
        int nova_letra = maior[i] - 'a'; 
        int letra_antiga = maior[i-n] - 'a';
        mapa_maior[nova_letra]++; 
        mapa_maior[letra_antiga]--;
        if(check_igual()) hash_perm.insert(h.get(i-n+1, i));  
        // printf("estou no intervalo %lld ,%lld e essa o valor de igual é %lld e o valor da string é %lld \n", i, i-n, igual,h.compute_string(i-n+1, i) );
    }
    cout << hash_perm.size() << "\n";
    return 0;
}