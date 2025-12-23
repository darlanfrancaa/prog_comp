#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int mdc(int a, int b){
    if(b == 0) return a; 
    return mdc(b, a%b);
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int l,a,b; cin >> l >> a >> b;  
        b = b % l;
        // eu quero encontrar o maior t tal que a + kb = t + lr -> 
        int d = mdc(l,b);
        // printf("achei o mdc %lld\n", d);
        a = a %l;
        int k = (l-a) / d;
        int ans = a + k*d;
        if(ans == l){
            ans = a + (k-1) * d;
        }
        cout << ans << "\n";
    }
    // cout << mdc(4,2) << "\n";
    return 0;
}