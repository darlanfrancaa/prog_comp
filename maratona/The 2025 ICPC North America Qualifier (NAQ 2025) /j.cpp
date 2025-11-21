#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int a[100];
    for(int i = 0; i < 100; i++){
        cin >> a[i];
    }

    int r = a[99] % 10;
    
    if(r == 0) {
        cout<< 10;
    }else{
        cout << r;
    }

    return 0;
}