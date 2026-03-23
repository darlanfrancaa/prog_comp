#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/1788/B

void solve(){
    int n; cin >> n; 
    int x = 0, y =0; 
    int pot = 1; 
    bool change = true;
    while(n> 0){
        int d = n%10;
        if(d%2 == 0){
            x += (d / 2) * pot;
            y += (d / 2) * pot;
        } else {
            if(change){
                x += (d/2 + 1) * pot;
                y += (d/2) * pot;
            } else {
                x += (d/2) * pot;
                y += (d/2 + 1) * pot;
            }
            change = !change;
        }
        n /= 10; 
        pot = pot * 10;
    }
    cout << x << " " << y << endl;
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    while(n--){
        solve();
    }
    return 0;
}