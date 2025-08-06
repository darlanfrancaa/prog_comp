#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, j, k; cin >> n >> j >> k; 
        vector<int> valores(n);
        for(auto &valor : valores) cin >> valor; 
        if(k >= 2) cout << "YES" << endl; 
        else {
            int valor = valores[j-1]; 
            bool maior = true; 
            for(int i=0;i<n;i++){
                if(valor < valores[i]) maior = false; 
            }
            if(maior) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}