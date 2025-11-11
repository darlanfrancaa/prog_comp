#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

void solve(){
    int qntd0 = 0, qntd1 = 0, qntdm1 = 0;
    int n; cin >> n; 
    for(int i=0;i<n;i++){
        int a; cin >> a; 
        if(a == 0) qntd0++;
        if(a == 1) qntd1++;
        if(a == -1) qntdm1++;
    }
    int qntd;
    if(qntdm1 % 2 == 0) qntd  = 0; 
    else qntd = 1;
    cout << qntd*2 + qntd0 << "\n";
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}