#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/2152/C

void solve(){
    int n, q; cin >> n >> q; 
    vector<int> a(n+1), diff(n+1), diff_total(n+1);
    vector<vector<int>> s(2, vector<int>(n+1));
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        s[0][i] = s[0][i-1];
        s[1][i] = s[1][i-1];
        s[a[i]][i]++;

        diff[i] = (a[i] != a[i-1]);
        diff_total[i] = diff_total[i-1] + diff[i];
    }
    for(int i=0;i<q;i++){
        int l, r; cin >> l >> r; 
        int zeros = s[0][r] - s[0][l-1];
        int uns = s[1][r] - s[1][l-1];
        if(zeros % 3 != 0 || uns % 3 != 0){
            cout << "-1\n";
            continue;
        }
        int qtd = zeros/3 + uns/3;
        if(diff_total[r] - diff_total[l] == (r-l)) qtd++; 
        cout << qtd << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}