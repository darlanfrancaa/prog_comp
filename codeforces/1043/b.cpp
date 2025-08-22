#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){ 
        ll n, contador = 0, div = 11; cin >> n; 
        vector<ll> ans; 
        while(div <= n){
            if(n % div == 0) { 
                contador++; 
                ans.push_back(n/div);
            } 
            div = 10*div - 9;
        }
        if(contador == 0) cout << 0 << "\n";
        else { 
            cout << contador << endl; 
            reverse(ans.begin(),ans.end());
            for(auto a:ans) cout << a << " "; 
            cout << "\n";
        }
    }
    return 0;
}