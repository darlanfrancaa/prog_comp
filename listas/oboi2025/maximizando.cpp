#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    double k; cin >> k;
    k = log(k);
    vector<double> vals(n+1);
    for(int i=1;i<=n;i++){
        int a; cin >> a; 
        vals[i] = log(a);
    } 
    for(int i=1;i<n;i++){
        if(vals[i] < vals[i+1]){
            k = k - vals[i] + vals[i+1];
        }
    };
    cout << fixed << setprecision(9) << k << "\n";
    return 0;
}