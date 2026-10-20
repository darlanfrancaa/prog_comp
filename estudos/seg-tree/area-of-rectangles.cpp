#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

const int normalizacao = 1e6;
const int M = 2e6+10;
static int mn[4*M], cnt[4*M], lz[4*M]; 

void pull(int p){
    int a = 2*p, b=2*p +1;
    if(mn[a] < mn[b]){
        mn[p] = mn[a]; 
        cnt[p] = cnt[a];
    }
    else if(mn[b] < mn[a]){
        mn[p] = mn[b]; 
        cnt[p] = cnt[b];
    }
    else {
        mn[p] = mn[a]; 
        cnt[p] = cnt[a] + cnt[b];
    }
}

void put(int p, int x){
    mn[p] += x; lz[p] += x;
} 
void push(int p){
    if(lz[p]) {
        put(2*p, lz[p]); 
        put(2*p+1, lz[p]); 
        lz[p] = 0;
    }
}

void build(int p, int l, int r){
    if(l==r) {
        // os valores de mn, lz já são inicializdos como 0
        cnt[p] = 1; 
        return;
    } 
    int m = (l+r)/2;
    build(2*p, l, m);
    build(2*p+1, m+1, r);
    pull(p);
}

void update(int p, int l, int r,int ql, int qr, int x){
    if(qr < l || r < ql) return;
    if(ql <= l && r <= qr) {
        put(p,x);
        return;
    }
    push(p);
    int m = (l+r)/2;
    update(2*p, l, m, ql, qr, x);
    update(2*p+1, m+1, r, ql, qr, x);
    pull(p);
}

int query(){
    return M - (mn[1] == 0 ? cnt[1] : 0);
}

// problem link: 

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<array<int, 4>> eventos;
    eventos.reserve(2*n);
    for(int i=0;i<n;i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        eventos.push_back({x1,y1,y2, +1});
        eventos.push_back({x2,y1,y2, -1});
    }
    sort(eventos.begin(), eventos.end());
    build(1, 0, M-1);
    int ans = 0; 
    int last_x = eventos[0][0];
    for(auto& [x,y1,y2,v]: eventos){
        ans += (x - last_x) * query();
        last_x = x; 
        update(1,0,M-1,y1+normalizacao, y2-1+normalizacao,v);
    }
    cout << ans << "\n";
    return 0;
}