#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/2160/C

void solve(){
    int n; cin >> n;
    if(n == 0){
        cout << "YES\n";
        return;
    }
    int l = 31, r = 0; 
    while(!(n & (1 << l))) l--;
    while(!(n & (1 << r))) r++;
    // vou encontrar o primeiro e último bits com 1 e eu quero saber se entre eles é palíndromo
    while(l > r){
        // cout << "loop\n";
        bool bl = n & (1 << l);
        bool br = n & (1 << r);
        if(bl != br) {
            cout << "NO\n";
            return; 
        } 
        l--;
        r++;
    }
    if(l == r){
        bool b = n & (1 << l);
        if(b){
            cout << "NO\n";
            return;
        } 
    }
    cout << "YES\n";
    return;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}