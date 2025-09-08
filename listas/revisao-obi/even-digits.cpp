#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link: https://atcoder.jp/contests/abc336/tasks/abc336_c

string solve (int n){
    n--;
    if(n==0){
        return "0";
    }
    string ret = "";
    while(n>0){
        int resto = n%5;
        char digito = (resto * 2) + '0';
        ret = digito + ret;
        n/=5;
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    cout << solve(n);
    return 0;
}