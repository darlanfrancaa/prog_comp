#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    vector<int> houses(n) , towers(m);
    for(auto &house : houses) cin >> house;
    for(auto &tower : towers) cin >> tower;
    int p = 0, q = 0;
    int max_dist = 0;
    while(p<n){
        while(q+1 < m && abs(towers[q+1]-houses[p]) <= abs(towers[q]-houses[p])) q++;
        max_dist = max(max_dist,abs(towers[q]-houses[p]));
        p++;
    }
    cout << max_dist;
    return 0;
}