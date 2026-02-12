#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1239

const int N = 1e6+10; 
int pot1[N], invpot1[N];
int pot2[N], invpot2[N];
const int m = 1e9+7;

int binpow(int a, int b, int mod){
    a %= mod; 
    int ret = 1; 
    while(b > 0){
        if(b % 2 == 1) ret = (ret * a) % mod; 
        a = (a * a) % mod; 
        b >>= 1; 
    }
    return ret;
}

void precompute(){
    int p1 = 467, p2 = 733;
    pot1[0] = 1; invpot1[0] = 1;
    pot2[0] = 1; invpot2[0] = 1;
    int invP1 = binpow(p1, m-2, m);
    int invP2 = binpow(p2, m-2, m);
    for(int i=1;i<N;i++){
        pot1[i] = (pot1[i-1] * p1) % m;
        invpot1[i] = (invpot1[i-1] * invP1) % m;

        pot2[i] = (pot2[i-1] * p2) % m;
        invpot2[i] = (invpot2[i-1] * invP2) % m;
    }
    
}

struct StringHash{
    vector<int> hash; 
    int *pot , *invpot;
    StringHash(int val){
        if(val == 1) {
            pot = pot1; invpot = invpot1;
        }
        if(val == 2) {
            pot = pot2; invpot = invpot2;
        }
    }
    void compute(string &s){
        int n = s.size();
        hash.resize(n+1);
        hash[0] = 0; 
        for(int i=0;i<n;i++){
            int val = s[i] - 'a' + 1; 
            hash[i+1] = (hash[i] + pot[i] * val) % m;
        }
    }

    int get_substring(int l, int r){
        l++; r++; 
        int ans = (hash[r] - hash[l-1] + m) % m;
        ans = (ans * invpot[l-1]) % m;
        return ans; 
    }
};

struct MergeHash {
    StringHash h1, h2;
    
    MergeHash() : h1(1), h2(2) {} 

    void compute(string &s){
        h1.compute(s);
        h2.compute(s);
    }
    
    pii get(int l, int r){
        return {h1.get_substring(l, r), h2.get_substring(l, r)};
    }
};


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    precompute();
    string s; 
    while(true){
        cin >> s; 
        if(s == ".") return 0; 
        int n = s.size();
        vector<int> divs; 
        for(int i=1;i * i <= n;i++){
            if(n%i == 0) {
                divs.push_back(i);
                if(i * i != n) divs.push_back(n/i);
            }
        }
        // for(int i=0;i<divs.size();i++){
        //     cout << divs[i] << ' ';
        // }
        MergeHash hash; 
        hash.compute(s); 
        int minimo = n;
        for(auto div: divs){
            if(div == n) continue;
            bool ok = true; 
            pii primeira = hash.get(0,div-1);
            for(int i = div;i<n;i+=div){
                if(primeira != hash.get(i,i+div-1)) {
                    ok = false;
                    break;
                }
            }
            if(ok) minimo = min(minimo, div);
        }
        cout << n/minimo << "\n";


    }

    return 0;
}