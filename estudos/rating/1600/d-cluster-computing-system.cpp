#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/2172/F

int mdc(int a, int b){
    if(a < b) swap(a,b);
    if(b == 0) return a;
    return mdc(b, a%b);

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    int vals[n+1]; 
    int pref[n+1], suf[n+1];
    for(int i=1;i<=n;i++){
        cin >> vals[i];
    }
    pref[1] = vals[1];
    suf[n] = vals[n];
    for(int i=2;i<=n;i++){
        pref[i] = mdc(pref[i-1], vals[i]);
    }
    for(int  i=n-1;i>=1;i--){
        suf[i] = mdc(suf[i+1], vals[i]);
    }
    int ans = 0;
    for(int i=1;i<n;i++){
        ans += min(pref[i], suf[i]);
    }
    cout << ans << "\n";
    return 0;
}