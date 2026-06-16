#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/2226/C

bool bin(vector<int> &v, int k){
    multiset<int> unused(v.begin(), v.end());
    for(int i=k-1;i>=0;i--){
        int val = i; 
        if(unused.count(val) >= 1) {
            unused.erase(unused.find(val));
        } else { 
            // então temos que procurar se tem alguém maior que 2x, basta olhar pro final e ver se ele é menor que 2x
            if(unused.empty()) return false;
            auto it = prev(unused.end());
            int num_end = *it;
            if(num_end <= 2*val) return false;
            unused.erase(it);
        }
    }
    return true;
}

void solve(){
    int n; cin >> n; 
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int left = 0, right = n+1;
    while(right - left > 1){
        // left funciona e right nunca funciona
        int mid = (left + right)/2;
        if(bin(v, mid)){
            left = mid; 
        } else right = mid;
    }
    cout << left << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}