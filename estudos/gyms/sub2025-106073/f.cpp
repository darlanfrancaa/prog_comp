#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: 

int exp(int a, int b){
    int res = 1;
    a %= MOD;
    while(b>0){
        if(b % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1; 
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    vector<int> ans(n+1), a(m);
    for(auto &x: a) cin >> x;
    int acc = 0;
    int inv2 = exp(2, MOD-2);
    for(int i=m-1;i>=0;i--){
        ans[a[i]] = (ans[a[i]] + acc * inv2) % MOD;
        acc = (acc + a[i]) * inv2 % MOD;
    }
    ans[1] = (ans[1] + acc) % MOD;
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
    return 0;
}