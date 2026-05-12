#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/gym/105394/problem/D

int fastpow(int b, int x){
    int ans = 1;
    b %= MOD;
    while(x > 0){
        if(x % 2 == 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        x /=2;
    }
    return ans;
}

int inv(int n){
    return fastpow(n, MOD-2);
}

struct BIT {
    int n; 
    vector<int> tree;

    BIT(int n): n(n), tree(n+1, 0){}

    void add(int i, int delta){
        delta = (delta % MOD + MOD) % MOD;
        for (; i <= n; i += i & -i) {
            tree[i] = (tree[i] + delta) % MOD;
        }
    }

    int query(int i){
        int sum = 0; 
        for(; i>0; i -= i & -i){
            sum = (sum + tree[i]) % MOD;
        }
        return sum;
    }

    int query(int l, int r){
        if(l > r) return 0; 
        return (query(r) - query(l-1) + MOD) % MOD;
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; 
    string p_str;
    cin >> n >> q >> p_str; 
    int num = 0, den = 1; 
    bool decimal = false; 
    for(char c: p_str){
        if(c == '.'){
            decimal = true;
        } else {
            num = num * 10 + (c - '0');
            if(decimal) den *= 10;
        }
    }

    int r_num = den - num; 
    int r = (r_num * inv(den)) % MOD;
    int inv_r = inv(r);

    vector<int> r_pow(n+1), r_inv(n+1);
    r_pow[0] = 1;
    r_inv[0] = 1; 
    for(int i=1; i<=n;i++){
        r_pow[i] = (r_pow[i-1] * r) % MOD;
        r_inv[i] = (r_inv[i-1] * inv_r) % MOD;
    }

    BIT bit_left(n);
    BIT bit_right(n);

    for(int i=0;i<q;i++){
        char op; cin >> op; 
        if(op == '+'){
            int b, y; cin >> b >> y; 
            b %= MOD;
            bit_left.add(y, b * r_inv[y] % MOD);
            bit_right.add(y, b * r_pow[y] % MOD);
        } else if(op == '-'){
            int b, y; cin >> b >> y; 
            b %= MOD; 
            bit_left.add(y, MOD - (b * r_inv[y] % MOD));
            bit_right.add(y, MOD - (b * r_pow[y] % MOD));
        } else {
            int x; cin >> x; 
            int sum_left = bit_left.query(1,x);
            int ans_left = (sum_left * r_pow[x]) % MOD;
            int sum_right = bit_right.query(x + 1, n);
            int ans_right = (sum_right * r_inv[x]) % MOD;
            int total = (ans_left + ans_right) % MOD;
            cout << total << "\n";
        }

    }
    return 0;
}