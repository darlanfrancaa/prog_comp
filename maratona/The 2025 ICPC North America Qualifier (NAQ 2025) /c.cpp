#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int minimo(int a, int b){
    if (a< b) return a; 
    return b;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k; 
    int count = 0; 
    set<int> mapa; 
    for(int i=0;i<n;i++){
        int a; cin >> a; 
        mapa.insert(a);
    }
    cout << minimo(mapa.size(), k) << "\n";
    return 0;
}