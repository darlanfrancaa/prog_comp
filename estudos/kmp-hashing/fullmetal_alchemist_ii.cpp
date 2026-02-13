#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/gym/104048/problem/K?mobile=false

const int tam_max = 1e4+10; 
const int mod = 1e9+7; 
const int p = 31;
const int MAXN = 20;

int pot[tam_max], invpot[tam_max];

int binpow(int a, int b, int m){
    a %= m; 
    int res = 1; 
    while(b > 0){
        if(b & 1) res = (res * a) % m; 
        a = (a * a)  % m; 
        b >>= 1; 
    }
    return res;
}

void precompute(){
    pot[0] = 1; invpot[0] = 1;
    int invp = binpow(p, mod-2, mod);
    for(int i=1;i<tam_max;i++){
        pot[i] = (pot[i-1] * p) % mod;
        invpot[i] = (invpot[i-1] * invp) % mod;
    }
}

struct Hash{
    int n; 
    vector<int> h;
    Hash(string &s){
        n = s.size();
        h.resize(n+1);
        h[0] = 0; 
        for(int i=0;i<n;i++){
            int val = s[i] - 'a' + 1; 
            h[i+1] = (h[i] + val * pot[i]) % mod;
        }
    }

    int compute_hash(int i, int j){
        int ret = (h[j+1] - h[i] + mod) % mod;
        ret  = (ret * invpot[i]) % mod;
        return ret;
    }
};

vector<string> pal_inicial, pal;
int adj[20][20];

int calc_pref(int ia, int ib, Hash &ha, Hash &hb){
    int tam_a = pal[ia].size(); 
    int tam_b = pal[ib].size(); 
    // quero retornar o maior valor tal que um sufixo do a é um prefixo do b
    for(int i = min(tam_a, tam_b); i >= 1; i--){
        if(ha.compute_hash(tam_a-i, tam_a-1) == hb.compute_hash(0,i-1)){
            return i;
        }
    }
    return 0;
}

int dp[(1 << MAXN)][MAXN];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    pal_inicial.resize(n);
    precompute();
    for(int i=0;i<n;i++) cin >> pal_inicial[i];
    vector<bool> final(n,true);
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            if(i == j) continue;
            if(pal_inicial[j].find(pal_inicial[i]) != string::npos){
                if(pal_inicial[i] == pal_inicial[j] && i<j) continue;
                final[i] = false; 
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(final[i]) pal.push_back(pal_inicial[i]);
    }
    n = pal.size(); 
    vector<Hash> hashed;
    for(string &s : pal) hashed.emplace_back(s);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = calc_pref(i,j,hashed[i], hashed[j]);
        }
    }

    for(int mask = 1; mask < (1 << n); mask++){
        for(int i=0;i<n;i++){
            dp[mask][i] = LLONG_MAX;
        }
    }

    for(int i=0;i<n;i++){
        dp[1 << i][i] = pal[i].size();
    }

    for(int mask = 1; mask < (1 << n); mask++){
        for(int i = 0;i<n;i++){
            if(!(mask & (1 << i))) continue; 
            if(dp[mask][i] == LLONG_MAX) continue;
            for(int j = 0; j<n;j++){
                if(mask & (1 << j)) continue;
                int new_mask = mask | (1 << j);
                int qntd_sum = pal[j].size() - adj[i][j];
                dp[new_mask][j] = min(dp[new_mask][j], dp[mask][i] + qntd_sum);
            }
        }
    }

    int ans = LLONG_MAX;
    int completo = (1 << n) - 1; 
    for(int i=0;i<n;i++){
        ans = min(ans, dp[completo][i]);
    }
    cout << ans << "\n";
    return 0;
}