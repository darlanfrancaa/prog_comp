#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 998244353;
const int N = 2e5+10;
const int B = 450;
// problem link: https://atcoder.jp/contests/abc335/tasks/abc335_f

int dp[N+10];
int lazy[N+10];
int resto[B][B];
vector<int> valores[B+10]; // quais são os valores 

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> a(n+1); 
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    dp[1] = 1;
    for(int i=1;i<=n;i++){
        int curr_sum = lazy[i];
        for(int k = 1; k < B; k++){
            curr_sum = (curr_sum + resto[k][i % k]) % MOD;
        }
        if(i == 1) curr_sum = (curr_sum + 1) % MOD;
        dp[i] = curr_sum;
        if(a[i] >= B){
            for(int j= i + a[i]; j<=n;j += a[i]){
                lazy[j] = (lazy[j] + dp[i]) % MOD;
            }
        } else {
            resto[a[i]][i % a[i]] = (resto[a[i]][i % a[i]] + dp[i]) % MOD;
        }
    }
    int ans = 0; 
    for(int i=1;i<=n;i++){
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}