#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/449/D

const int BITS = 20; 
const int MAX_MASK = (1 << BITS);

int dp[MAX_MASK];
int pot2[1000005];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    pot2[0] = 1; 
    for(int i=1;i<=n;i++){
        pot2[i] = (pot2[i-1] * 2) % MOD; 
    }

    for(int i=0;i<n;i++){
        int val; cin >> val; 
        dp[val]++;
    }

    for(int i=0;i<BITS;i++){
        for(int mask = MAX_MASK-1; mask >=0; mask--){
            if(!(mask & (1 << i))) {
                dp[mask] += dp[mask | (1 << i)];
            }
        }
    }
    // essa dp calcula o número de superconjuntos dentre os ais que existem pra cada x
    int ans = 0; 
    for(int mask=0; mask < MAX_MASK; mask++){
        int qtd = (pot2[dp[mask]] - 1 + MOD) % MOD;
        int uns = __builtin_popcount(mask); 
        if (uns % 2 == 1){
            ans = (ans - qtd + MOD) % MOD;
        } else { 
            ans = (ans + qtd + MOD) % MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}