#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int,int>;
const int MOD = 998244353;

/*Link do problema: https://judge.yosupo.jp/problem/queue_operate_all_composite */

ll potencia(ll a, ll n){
    a %= MOD;
    ll ans = 1;
    while(n > 0){
        if (n%2==1) ans = (ans * a) % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    int acomp_x = 1;
    int solto = 0;
    queue<pii> funcoes;
    while(q--){
        int op; cin >> op;
        if(op == 0){
            int a, b; cin >> a >> b;
            funcoes.push({a,b});
            acomp_x = (acomp_x*a) % MOD;
            solto = ((solto * a) % MOD + b) % MOD;
        }
        else if(op == 1) {
            auto [a,b] = funcoes.front();
            funcoes.pop();
            ll inv = potencia(a, MOD-2);
            acomp_x = ( acomp_x * inv) % MOD;
            solto -= (b * acomp_x) % MOD;
        } else if(op == 2){
            int num; cin >> num;
            cout << (acomp_x * num + solto) % MOD << endl;
        }
    }
    return 0;
}