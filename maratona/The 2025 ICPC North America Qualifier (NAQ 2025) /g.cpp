#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 998244353;

int fastpow(int base, int exp){
    int pow = 1;
    while(exp){
        if(exp & 1){
            pow = ((pow * base) % MOD);
        }
        base = ((base*base) % MOD);
        exp = exp >> 1;
    }
    return pow;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;

    int p = (n * fastpow(2*k,2*k) % MOD);
    int q = fastpow(2*k + 1, 2*k);
    int invq = fastpow(q, MOD-2);

    cout << (p*invq) % MOD << endl;;

    return 0;
}