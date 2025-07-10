#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

/*link: https://judge.yosupo.jp/problem/montmort_number_mod*/

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m; cin >> n >> m; 
    ll ans = 1;
    for(int i=1;i<=n;i++){
        ans = ((ans * i)% m) + (i % 2 == 1? -1 : 1);
        ans = (ans + m) % m;
        cout << ans << " ";
    }
    cout << endl;
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}