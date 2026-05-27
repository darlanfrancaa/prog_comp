#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1654

const int M = 20; 
const int max_bits = 1 << M;

int dp[max_bits];
int dp_inv[max_bits];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> a(n);
    int maximo = max_bits - 1;
    for(int i=0;i<n;i++){
        cin >> a[i];
        dp[a[i]]++;
        dp_inv[(~a[i]) & maximo]++; // adiciono a mask negada também
    }

    for(int i=0;i<M;i++){
        for(int mask = 0; mask < maximo; mask++){
            if(mask & (1 << i)){
                dp[mask] += dp[mask ^ (1<< i)];
                dp_inv[mask] += dp_inv[mask ^ (1 << i)];
            } 
        }
    }

    for(int i=0;i<n;i++){
        int x = a[i];
        int x_negado = (~x) & maximo;
        int ans1 = dp[x];
        int ans2 = dp_inv[x_negado];
        int ans3 = n - dp[x_negado];
        cout << ans1 << " " << ans2 << " " << ans3 << "\n";
    }
    
    return 0;
}