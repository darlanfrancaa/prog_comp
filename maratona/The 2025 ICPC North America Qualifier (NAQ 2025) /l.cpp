#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    int v[n];
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int res1, res2, res3;
    res1 = v[0]/3;
    res3 = v[n-1]/3;
    res2 = v[1] - 2*res1;

    cout << res1 << " " << res2 << " " << res3 << "\n";
    return 0;
}