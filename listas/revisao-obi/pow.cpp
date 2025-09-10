#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, c; 
    cin >> a >> b >> c; 
    if(c % 2 == 0){
        if(abs(a) == abs(b)) cout << "=";
        else if(abs(a) < abs(b)) cout << "<";
        else if(abs(a) > abs(b)) cout << ">";
    } else { 
        if(a > b) cout << ">";
        else if(a == b) cout << "="; 
        else cout << "<";
    }
    return 0;
}