#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: 

void solve(){
    int n, m, k; cin >> n >> m >> k; 
    vector<int> a(n), b(m);
    vector<bool> v1(k+1, false), v2(k+1, false);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(1 <= a[i] && a[i] <= k) v1[a[i]] = true;
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
        if(1 <= b[i] && b[i] <= k) v2[b[i]] = true;
    }
    int q1 = 0, q2 = 0; 
    for(int i=1;i<=k;i++){
        if(!v1[i] && !v2[i]){
            // cout << "não tem os dois valores para i = " << i << "\n";
            cout << "NO\n"; 
            return;
        } else if (v1[i] && v2[i]){
            continue;
        } else { 
            if(v1[i]) q1++;
            else q2++;
        }
    }

    // cout << "chegou aqui\n";

    if(q1 <= k/2 && q2 <= k/2) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}