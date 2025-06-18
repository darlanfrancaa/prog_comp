#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int raiz(int x){
    return sqrt(x);
}

int main() {
    int t; cin >> t;
    while(t>0){
        t--;
        int x; cin >> x;
        if(raiz(x)*raiz(x) != x) cout << -1 << endl;
        else cout << 0 << " " << raiz(x) << endl;
    }
    return 0;
}