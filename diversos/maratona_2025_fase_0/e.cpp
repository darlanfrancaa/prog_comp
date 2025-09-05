#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

vector<int> fact(int k){
    vector<int> ans;
    for(int i=2;i*i<=k;i++){
        while(k%i==0){
            ans.push_back(i);
            k /= i;
        }
    }
    if(k > 1){
        ans.push_back(k);
    }
    return ans;
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int y, k; cin >> y >> k;
    vector<int> v = fact(y);
    int ans = 1;
    int i=0;
    while(i < v.size() && k - v[i] >= 0){
        ans *= v[i];
        k-= (v[i]-1);
        i++;
    }
    if(k==0) cout << ans << "\n";
    else{
        ans += k*ans;
        cout << ans << "\n";
    }
    return 0;
}