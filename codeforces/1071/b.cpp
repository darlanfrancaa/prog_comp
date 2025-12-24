#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n; 
    vector<int> v(n);
    for(auto &a: v) cin >> a; 
    int sum = 0;
    for(int i=0;i<n-1;i++){
        int s = v[i] - v[i+1];
        s = abs(s);
        sum += s;
    }
    // cout << "o valor de sum é:" << sum << '\n';
    int minimo = LLONG_MAX; 
    for(int i=0;i<=n-1;i++){
        int atual = sum;
        if(i==0){
            atual -= abs(v[0] - v[1]);
        } else if(i == n - 1){
            atual -= abs(v[n-2] - v[n-1]);
        } else {
            atual -= abs(v[i] - v[i-1]);
            atual -= abs(v[i+1] - v[i]);
            atual += abs(v[i-1] - v[i+1]);
        }
        minimo = min(minimo, atual);
    }
    cout << minimo << "\n";
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}