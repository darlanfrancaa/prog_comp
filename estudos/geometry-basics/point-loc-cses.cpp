#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/2189

void solve(){
    int x1, y1, x2, y2, x3, y3; 
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3; 
    pii a = {x2-x1, y2-y1};
    pii b = {x3-x1, y3-y1};
    
    int prod = a.first * b.second - a.second * b.first;
    if(prod > 0) cout << "LEFT\n"; 
    else if (prod == 0) cout << "TOUCH\n";
    else cout << "RIGHT\n";
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