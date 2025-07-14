#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

/*link: https://dmoj.ca/problem/bbc08h*/

ll exp(ll a, ll b){
    a %= MOD;
    int ret = 1;
    while(b>0){
        if(b % 2 == 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ret;
}

ll fatorial(int n){
    ll ans = 1;
    for(int i = 2;i<=n;i++){
        ans = ans * i % MOD;
    }
    return ans;
}

ll inverso(int k){
    return exp(k, MOD-2);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    ll ans = 1;
    ans *= fatorial(2*n+2);
    ans = ans * inverso(fatorial(n+1)) % MOD * inverso(fatorial(n+1)) % MOD;
    ans -= 1;
    cout << ans << endl;
    return 0;
}