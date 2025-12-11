#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        if(n==1){
            int a; cin >> a; 
            cout << 0 << "\n";
            continue;
        }
        vector<int> v(n);
        for(auto &a: v) cin >> a; 
        vector<int> rem(n, 0);
        int l = n-2, r = n-1;
        int contador = 0;
        while(l >= 0){
            // cout << "estou em l = " << l << "\n";
            while(r < n && v[l] > v[r]){
                rem[r] = true; 
                contador++;
                while(r < n && rem[r] == true) r++; // isso aqui para no primeiro não removido;
            }
            r = l; 
            l -= 1; 
        }
        cout << contador << "\n";
    }
    return 0;
}