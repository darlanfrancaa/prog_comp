#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/1790/D

void solve(){
    int n; cin >> n; 
    multiset<int> s;
    for(int i=0;i<n;i++){
        int val; cin >> val; 
        s.insert(val);
    }
    int qtd=0; 
    while(!s.empty()){
        // cout << "comecando um novo\n";
        qtd++;
        auto it = s.begin();
        int val = *it; 
        // cout << "primeiro valor = " << val << "\n";
        s.erase(it);
        while(true){
            val++; 
            it = s.find(val);
            if(it == s.end()) break;
            s.erase(it);
            // cout << "o proximo valor = " << val << " foi encontrado\n";
        }
        
    }
    // cout << " =============================== \n";
    // cout << "no fim para esse caso a resposta foi :" << qtd << "\n";
    cout << qtd << "\n";
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}