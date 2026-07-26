#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: 



void op(int idx, string &s, int n, int k){
    for(int i=0;i<k && (idx+i) <n;i++){
        s[idx + i] = '1';
    }     
}

void solve(){
    int n, m, k; 
    cin >> n >> m >> k; 
    string s; cin >> s; 
    int qtd0 = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        // cout << "entrei na posição " << i << " da string\n";
        if(s[i] == '1'){
            qtd0 = 0;
            // cout << "tem um 1 e agr qtd0 vale" << qtd0 << endl;
        } else {
            qtd0++;
            // cout << "agora tem " << qtd0 << " 0s consecutivos vou fazer operação nele se for = m\n";
            if(qtd0 == m){
                
                ans++;
                // cout << "fazendo operação\n";
                op(i, s,n,k);
                qtd0 = 0;
            } 
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >>t; 
    while(t--){
        solve();
    }
    return 0;
}