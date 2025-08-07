#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        int contador = 0;
        string numero; cin >> numero;
        for(int i=0;i<n;i++){
            int a = numero[i] - '0';
            if (a == 1) contador++;
        }
        if(contador <= k) cout << "Alice" << endl ;
        else { 
            if(n >= 2 * k) cout << "Bob" << endl;
            else cout << "Alice" << endl;
        }
    }
    return 0;
}