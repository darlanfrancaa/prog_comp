#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1647

const int N = 2e5 + 10;
const int LOG = 23;
int v[N];
int dp[N][LOG]; 

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    for(int i=1;i<=n;i++){
        cin >> v[i];
        dp[i][0] = v[i];
    }

    for(int j=1;j<LOG;j++){
        for(int i=1;i + (1 << j) -1 <=n;i++){
            dp[i][j] = min(dp[i][j-1], dp[i + (1 << (j-1))][j-1]);
        }
    }
    int lg[N];
    lg[1] = 0;
    for(int i = 2; i < N; i++)
        lg[i] = lg[i/2] + 1;

    while(q--){
        int l, r; cin >> l >> r; 
        int meio = lg[r - l + 1];
        cout << min(dp[l][meio], dp[r - (1 << meio) + 1][meio]) << "\n";
    }
    return 0;
}