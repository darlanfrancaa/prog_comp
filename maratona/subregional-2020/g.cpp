#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n ; cin >> n; 
    int maximo = 0, soma = 0;
    while(n--){
        int a; cin >> a; 
        soma += a; 
        maximo = max(maximo, soma);
    }
    cout << 100 + maximo;
    return 0;
}