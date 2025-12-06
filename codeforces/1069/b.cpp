#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; int l,r; cin >> n >> l >> r; 
        vector<int> pref(n+1);
        pref[l-1] = 0;
        pref[r] = 0;
        // então eu quero fazer um vetor onde todo mundo é diferente tirando o l,r = 0;
        int it = 0; 
        int contador = 1; 
        while(it <= n){
            if(it == l-1 || it == r) {
                it++;
                continue;
            }
            pref[it] = contador; 
            contador++; it++;
        }
        vector<int> ans(n+1);
        ans[0] = pref[0];
        for(int i=1;i<=n;i++){
            ans[i] = pref[i] ^ pref[i-1];   
        }
        for(int i=1;i<=n;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}