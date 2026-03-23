#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/1459/A

void solve(){
    int t; cin >> t; 
    int red[t], blue[t];
    for(int i=0;i<t;i++){
        char c; cin >> c; 
        red[i] = c - '0';
    }
    for(int i=0;i<t;i++){
        char c; cin >> c; 
        blue[i] = c - '0';
    }
    int qntd_red = 0, qntd_blue = 0; 
    for(int i=0;i<t;i++){
        if(red[i] > blue[i]) qntd_red++;
        else if(red[i] < blue[i]) qntd_blue++;
    }
    if(qntd_red > qntd_blue) cout << "RED" << endl;
    else if(qntd_red < qntd_blue) cout << "BLUE" << endl;
    else cout << "EQUAL" << endl;

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    while(n--){
        solve();
    }
    return 0;
}