#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    multiset<int> towers;
    for(int i = 0;i<n;i++){
        int curr; cin >> curr; 
        auto it = towers.upper_bound(curr);
        if(it == towers.end()){
            towers.insert(curr);
        } else { 
            towers.erase(it);
            towers.insert(curr);
        }
    }
    cout << towers.size();
    return 0;
}