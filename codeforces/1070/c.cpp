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
        vector<int> pares, impares; 
        for(int i=0;i<n;i++){
            int a; cin >> a; 
            if(a % 2 == 1) impares.push_back(a);
            else pares.push_back(a);
        }
        sort(impares.begin(), impares.end());
        sort(pares.begin(),pares.end(),greater<int>());

        int n_pares = pares.size();
        vector<int> pref(n_pares+1,0);
        for(int i=0;i<n_pares;i++){
            pref[i+1] = pref[i] + pares[i];
        }
        for(int k = 1; k <= n; k++){
            if(impares.empty()){
                cout << 0 << " ";
                continue;
            }
            int qtd_pares = min((int)pares.size(), k-1);
            int qtd_impares = k - qtd_pares;
            if(qtd_impares % 2 == 0) {
                qtd_pares--;
                qtd_impares++;
            }
            if(qtd_pares < 0 || qtd_impares > impares.size()) {
                cout << 0 << " ";
            } else {
                int ans = impares.back() + pref[qtd_pares];
                cout << ans << " ";
            }
        }   
        cout << '\n';
    }
    return 0;
}