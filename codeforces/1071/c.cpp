#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b, a%b);
}

void solve(){
    int n; cin >> n; 
    vector<int> v(n);
    for(auto &a: v) cin >> a; 
    int minimo = LLONG_MAX;
    for(int i=0;i<n;i++){
        minimo = min(minimo, v[i]);
    }
    // cout << "minimo" << minimo << "\n";
    vector<int> diff;
    for(int i=0;i<n;i++){
        int d = abs(v[i] - minimo);
        if(d != 0) diff.push_back(d);
    }
    int m = LLONG_MAX;
    for(int i=0;i<diff.size();i++){
        m = min(m,diff[i]);
    }
    cout << max(m, minimo) << "\n";

}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}