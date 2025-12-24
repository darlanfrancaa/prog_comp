#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n; 
    for(int d=n;d>=0;d--){
        // então eu quero colocar d dígitos 1, colocar um 0 e colocar todos os valores de 0 até 2^{n-d-1} 
        if(d == n){
            int num = (1LL << n) - 1;
            cout << num << " ";
            continue;
        }
        int end = (1LL << d) - 1;
        for(int mask = 0; mask < (1LL << (n-d-1)); mask++){
            int new_mask = (int)mask << d+1;
            int num = new_mask | end;
            cout << num << " ";
        }
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}