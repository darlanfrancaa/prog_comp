#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link : https://codeforces.com/problemset/problem/1738/B

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> v(k);
        for(auto &a : v) cin >> a;
        if(k==1){
            cout << "YES\n";
            continue;
        }
        bool certo = true;
        int num_anterior = LLONG_MAX, num = LLONG_MAX, fim; 
        for(int i=k-1;i>=1;--i){
            num_anterior = num;
            num = v[i] - v[i-1];
            if(num > num_anterior) certo = false;
        }
        if(num * (n-k+1) < v[0]) certo = false;
        if(certo) cout << "YES\n";
        else cout << "NO\n"; 
    }
    return 0;
}