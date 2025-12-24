#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

void solve(){
    int n, x, y; cin >> n >> x >> y; 
    string mask; cin >> mask;
    vector<int> p(n);
    int sum_total = 0, sum_x = 0, sum_y = 0;
    int count_0 = 0, count_1 = 0; 
    for(int i=0;i<n;i++){
        cin >> p[i];
        sum_total += p[i];
        int num = p[i]/2 + 1; // esse é o primeiro valor que funciona
        if(mask[i] == '0'){
            sum_x += num;
            count_0++;
        } else {
            sum_y += num; 
            count_1++;
        }
    }
    bool ok = true;
    if(x + y < sum_total) ok = false; 
    if(x < sum_x || y < sum_y) ok = false;
    if(count_0 == 0 && y < x + n) ok = false;
    if(count_1 == 0 && x < y + n) ok = false;
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}