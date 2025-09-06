#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int find_lis(const vector<int> &v){
    vector<int> dp;
    for(auto i:v){
        int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
        if(pos == dp.size()){
            dp.push_back(i);
        } else {
            dp[pos] = i;
        }
    }
    return dp.size();
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(auto &value: v) cin >> value;
    cout << find_lis(v);
    return 0;
}