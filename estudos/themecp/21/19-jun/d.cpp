#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/1878/D

void solve(){
    int n, k; cin >> n >> k; 
    string s; 
    cin >> s; 
    vector<int> a(k), b(k);
    for(int i=0;i<k;i++) {
        cin >> a[i]; 
        a[i]--; 
    }
    for(int i=0;i<k;i++){
        cin >> b[i];
        b[i]--;
    }
    int q; 
    cin >> q;
    vector<int> qtd(n+1,0);
    for(int i=0;i<q;i++){
        int x; cin >> x; 
        qtd[x-1]++;
    }
    string ans = "";
    for(int i=0;i<k;i++){
        string sub = s.substr(a[i], b[i]-a[i]+1);
        int soma = 0;
        int l=a[i];
        int r=b[i];
        for(int j=l; j<= (l+r)/2;j++){
            soma += qtd[j] + qtd[r-j+l];
            if(soma%2 == 1) swap(sub[j-l], sub[r-j]);
        }
        ans += sub;
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}