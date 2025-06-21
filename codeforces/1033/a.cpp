#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t>0){
        t--;
        int l1,b1,l2,b2,l3,b3; cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        bool check = false;
        if(l1 == l2 && l2 == l3 && b1 + b2 + b3 == l1) check = true;
        else if(b1 == b2 && b2 == b3 && l1 + l2 + l3 == b1) check = true;
        else if(l1 == l2 + l3 && b2 == b3 && b1 + b2 == l1 ) check = true;
        else if(b1 == b2 + b3 && l2 == l3 && l1 + l2 == b1) check = true;
        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}