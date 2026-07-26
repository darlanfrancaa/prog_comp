#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: 
int n; 

int solve_xy(int x, int y) {
    x--; y--; 
    int ans = 0; 
    
    for(int bit = n - 1; bit >= 0; bit--) {
        int bx = (x >> bit) & 1;
        int by = (y >> bit) & 1;
        
        int quad = 0;
        if(bx == 0 && by == 0) quad = 0; 
        if(bx == 1 && by == 1) quad = 1; 
        if(bx == 1 && by == 0) quad = 2; 
        if(bx == 0 && by == 1) quad = 3; 
        
        ans = (ans << 2) | quad;
    }
    return ans + 1; 
}

pii findk(int d) {
    d--; 
    int x = 0, y = 0;
    
    for(int bit = n - 1; bit >= 0; bit--) {
        int quad = (d >> (2 * bit)) & 3;
        
        int bx = 0, by = 0;
        if(quad == 0) { bx = 0; by = 0; }
        if(quad == 1) { bx = 1; by = 1; }
        if(quad == 2) { bx = 1; by = 0; }
        if(quad == 3) { bx = 0; by = 1; }
        
        x = (x << 1) | bx;
        y = (y << 1) | by;
    }
    return {x + 1, y + 1}; 
}

void solve() {
    int q; 
    cin >> n >> q;
    
    while(q--) {
        string op;
        cin >> op;
        if(op == "->") {
            int x, y;
            cin >> x >> y;
            cout << solve_xy(x, y) << "\n";
        } else {
            int d;
            cin >> d;
            pii coords = findk(d);
            cout << coords.first << " " << coords.second << "\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; 
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}