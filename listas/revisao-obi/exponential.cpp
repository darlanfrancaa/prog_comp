#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        if( n % 2 == 1) {
            cout << -1 << "\n";
            continue;
        } else { 
            cout << 1 << " " << n /2 << "\n";
            continue;
        }
    }
    return 0;
}