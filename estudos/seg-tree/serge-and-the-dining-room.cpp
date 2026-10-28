#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/1179/C

const int VAL  = 1e6+2;
static int mx[4*(VAL + 1)], lz[4*(VAL+1)];

// As queries vão ser de máximo de f em um intervalo, e a lazy tag vai ser de somar 1 em todo o intervalo

void put(int p, int x){
    mx[p] += x; lz[p] += x; 
    return;
}

void push(int p){
    if(lz[p]) {
        put(2*p, lz[p]);
        put(2*p+1, lz[p]);
        lz[p] = 0;
    }
}

void pull(int p){
    mx[p] = max(mx[2*p], mx[2*p+1]);
}

void build(int p, int l, int r, const vector<int> &f){
    if(l == r){
        mx[p] = f[l]; 
        return;
    }
    int m = (l+r)/2;
    build(2*p, l, m, f); 
    build(2*p+1, m+1, r, f);
    pull(p); 
}

void update(int p, int l, int r, int ql, int qr, int x){
    if(qr < l || r < ql) return;
    if(ql <= l && r <= qr) {
        put(p, x);
        return;
    }
    push(p);
    int m = (l+r)/2;
    update(2*p, l, m, ql, qr, x);
    update(2*p+1, m+1, r, ql, qr, x);
    pull(p);
}


// maior x com f(x) > 0, ou -1
int query() {
    if(mx[1] <= 0) return -1;
    int p = 1, l = 1, r = VAL;
    while(l < r){
        push(p);
        int m = (l+r)/2;
        if(mx[2*p+1] > 0) {
            p = 2*p+1; l = m+1;
        } else {
            p = 2*p; r = m;
        }
    }
    return l;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    vector<int> f(VAL+2,0);
    vector<int> a(n), b(m);
    for(auto &x: a) {
        cin >> x; 
        f[x]++; 
    }
    for(auto &x: b) {
        cin >> x; 
        f[x]--;
    }
    for (int x = VAL - 1; x >= 1; x--) f[x] += f[x + 1];  
    build(1, 1, VAL, f);

    int q; cin >> q;
    while (q--) {
        int t, i, x; cin >> t >> i >> x; i--;
        if (t == 1) {                       
            update(1, 1, VAL, 1, a[i], -1);
            a[i] = x;
            update(1, 1, VAL, 1, a[i], +1);
        } else {                           
            update(1, 1, VAL, 1, b[i], +1);
            b[i] = x;
            update(1, 1, VAL, 1, b[i], -1);
        }
        cout << query() << '\n';
    }

    return 0;
}