#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k; 
    map<int,int> mapa; 
    for(int i=0;i<n;i++){
        int a; cin >> a; 
        mapa[a]++;
    }
    int contador = 0; 
    for(int i=0;i<k;i++){
        if(mapa[i] == 0) contador++;
    }
    cout << max(contador, mapa[k]) << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}