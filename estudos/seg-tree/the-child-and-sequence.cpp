#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: 

const int MAXN = 1e5+10;
int v[MAXN];
int maximo[4*MAXN], soma[4*MAXN];

void pull(int p){
    int l = 2*p, r = 2*p+1;
    maximo[p] = max(maximo[l], maximo[r]);
    soma[p] = soma[l] + soma[r];
    return;
}

void build(int p, int l, int r){
    if(l==r){
        maximo[p] = v[l];
        soma[p] = v[l]; 
        return;
    }
    int m = (l+r)/2;
    build(2*p, l, m);
    build(2*p+1, m+1, r);
    pull(p);
}

int query_soma(int p, int l, int r, int ql, int qr){
    if(ql > r || qr < l) return 0;
    if(ql <= l && r <= qr) return soma[p];
    int m = (l+r)/2;
    int q1 = query_soma(2*p, l, m, ql, qr);
    int q2 = query_soma(2*p+1, m+1, r, ql, qr);
    return q1 + q2;
}


int query_max(int p, int l, int r, int ql, int qr){
    if(ql > r || qr < l) return LLONG_MIN;
    if(ql <= l && r <= qr) return maximo[p];
    int m = (l+r)/2;
    int q1 = query_max(2*p, l, m, ql, qr);
    int q2 = query_max(2*p+1, m, r, ql, qr);
    return max(q1,q2);
}

void update_mod(int p, int l, int r, int ql, int qr, int mod){
    if (qr < l || r < ql || maximo[p] < mod) return;
    if(l == r && ql <= l && l <= qr){
        // é uma folha do intervalo
        maximo[p] = maximo[p] % mod;
        soma[p] = soma[p] % mod;
        return;
    }
    int m = (l+r)/2;
    if(ql <= m) update_mod(2*p, l, m, ql, qr, mod);
    if(qr > m) update_mod(2*p+1, m+1,r, ql,qr,mod);
    pull(p);
    
}

void update_change(int p, int l, int r, int pos, int val){
    if(l == r){
        maximo[p] = val;
        soma[p] = val;
        return;
    }
    int m = (l+r)/2;
    if(pos <= m) update_change(2*p, l, m,pos,val);
    else update_change(2*p+1, m+1, r, pos, val);
    pull(p);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    for(int i=0;i<n;i++) cin >> v[i];
    build(1, 0, n-1);
    for(int i=0;i<m;i++){
        int op; cin >> op; 
        if(op == 1){
            int l, r; cin >> l >> r; l--, r--;
            cout << query_soma(1,0,n-1,l,r) << "\n";
        } else if (op == 2){
            int l, r, mod; cin >> l >> r >> mod; l--, r--;
            update_mod(1,0,n-1,l,r, mod);
        } else {
            int pos, val; cin >> pos >> val; pos--;
            update_change(1,0,n-1,pos,val);
        }
    }
    
    return 0;
}