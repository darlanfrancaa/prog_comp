#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link : https://cses.fi/problemset/task/1754

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int a, b; cin >> a >> b;
        if (a > b) swap(a,b);
        if ((a+b) % 3 != 0) {
            cout << "NO" << "\n";
            continue;
        } else {
            if(b <= 2*a) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }
    return 0;
}