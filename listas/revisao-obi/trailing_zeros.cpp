#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    int pot = 5, contador = 0;
    while(pot <= n){
        contador += (n/pot);
        pot *= 5; 
    }
    cout << contador << "\n";
    return 0;
}