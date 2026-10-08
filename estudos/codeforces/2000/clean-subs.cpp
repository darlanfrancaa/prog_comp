#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link:

void solve(){
    int n,q; cin >> n >> q; 
    string s; cin >> s; s = " " + s;

    vector<int> b(n+1,0);
    int ans = 0; 
    int q0 = 0, q1 = 0; 
    for(int i=1;i<=n;i++){
        if(s[i] == '0') q0++;
        else q1++;
    }

    for(int i=1; i<n; i++){
        if(s[i] != s[i+1]) b[i] = 1;
        else b[i] = 0;
        if (b[i]) ans += i * (n-i);
    }

    auto get_ans = [&]() -> int {
        return (ans + q0 * q1)/2;
    };

    cout << get_ans() << " ";

    auto update = [&](int idx, int novo_val) {
        if (b[idx] == novo_val) return;
        if (b[idx]) ans -= idx * (n - idx);    
        b[idx] = novo_val;
        if (b[idx]) ans += idx * (n - idx);
    };
    while(q--){
        int pos; cin >> pos; 
        if(s[pos] == '0'){
            q0--;
            q1++;
            s[pos] = '1';
        } else {
            q0++; 
            q1--;
            s[pos] = '0';
        }
        if (pos > 1) {
            update(pos - 1,(s[pos - 1] != s[pos]) ? 1 : 0);
        }
        if (pos < n) {
            update(pos,(s[pos] != s[pos + 1]) ? 1 : 0);
        }
        cout<< get_ans() << " ";
    }

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
        cout << "\n";
    }   
    return 0;
}