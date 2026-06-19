#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/1979/B

int pot[35];

void precalc(){
    pot[0] = 1; 
    for(int i=1;i<33;i++){
        pot[i] = pot[i-1] * 2;
    }
}

void solve(){
    int a, b; cin >> a >> b;
    int qtd = 0;
    while(a >= 0 && b >= 0){
        if(a % 2 == b % 2){
            qtd++;
            a >>= 1; 
            b >>= 1;
        }
        else break;
    }
    cout << pot[qtd] << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    precalc();
    while(t--){
        solve();
    }
    return 0;
}