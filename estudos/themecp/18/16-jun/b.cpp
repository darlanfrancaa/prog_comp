#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/2197/B

void solve(){
    int n; cin >> n; 
    vector<int> a(n+1);
    vector<int> pos(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        int val; cin >> val;     
        ans.push_back(pos[val]);
    }
    bool ord = is_sorted(ans.begin(), ans.end());
    if(ord) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}