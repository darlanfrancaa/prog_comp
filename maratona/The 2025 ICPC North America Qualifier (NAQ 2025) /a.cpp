#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int r, g, b; cin >> r >> g >> b; 
    int cr,cg,cb; cin >> cr >> cg >> cb; 
    r -= cr; g -= cg; b -= cb; 
    if(r < 0) r = 0;
    if(g < 0) g = 0;
    if(b < 0) b = 0;
    int t1, t2; cin >> t1 >> t2; 
    int count = 0;
    if(r > 0){ 
        if(t1 < r) {
            cout << -1 << "\n"; 
            return 0;
        } else { 
            t1 -= r; 
            count += r;
        }
    }  
    if(b > 0){
        if(t2 < b){ 
            cout << -1 << "\n"; 
            return 0;
        } else { 
            t2 -= b;
            count += b;
        }
    }
    if(g > 0){
        if(t1 + t2 < g){
            cout << -1 << "\n"; 
            return 0;
        } else {
            count += g;
        }
    }
    cout << count << "\n";
    
    return 0;
}