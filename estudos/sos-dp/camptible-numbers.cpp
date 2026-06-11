#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/contest/165/problem/E

const int BITS = 22; 
const int MAXM = (1LL << BITS);
const int MAX_BITS = MAXM - 1;
int val[MAXM];
int dp[MAXM];
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        int x; cin >> x;
        a[i] = x; 
        dp[x] = x;
    }
    for(int i=0;i<BITS;i++){
        for(int mask = 0; mask < MAXM; mask++){
            // a ideia é que se algum valor aparecer como submask dele então dp mask vai salvar o maior desses valores que é submask
            if(mask & (1 << i)) dp[mask] = max(dp[mask], dp[mask ^ (1LL << i)]);
        }
    } 
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        int val_ng = MAX_BITS ^ a[i];
        if(dp[val_ng] != 0) ans[i] = dp[val_ng];
    }

    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }


    return 0;
}