#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://atcoder.jp/contests/abc250/tasks/abc250_e

map<int,int> val; 

int get_rand(int x){
    if(val.find(x) == val.end()){
        int r = 0; 
        for(int i=0;i<5;i++) r = (r << 15) ^ rand();
        val[x] = r;
    }
    return val[x];
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    vector<int> h_a(n+1,0), h_b(n+1,0);
    set<int> conj_a, conj_b;
    for(int i=0;i<n;i++){
        h_a[i+1] = h_a[i];
        if(conj_a.find(a[i]) == conj_a.end()){
            conj_a.insert(a[i]);
            h_a[i+1] ^= get_rand(a[i]);
        }
    } 
    for(int i=0;i<n;i++){
        h_b[i+1] = h_b[i];
        if(conj_b.find(b[i]) == conj_b.end()){
            conj_b.insert(b[i]);
            h_b[i+1] ^= get_rand(b[i]);
        }
    }
    int q;
    cin >> q; 
    while(q--){
        int x,y; cin >> x >> y; 
        if(h_a[x] == h_b[y]){
            cout << "Yes\n";
        } else { 
            cout << "No\n";
        }
    }
    return 0;
}