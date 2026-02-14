#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/2061/D

bool solve(){
    int n, m; cin >> n >> m; 
    multiset<int> a,b; 
    for(int i=0;i<n;i++) {
        int num; cin >> num; 
        a.insert(num);
    }   
    for(int i=0;i<m;i++){
        int num; cin >> num; 
        b.insert(num);
    }
    int qntd = 0;  
    if(n < m) return false;
    while(qntd < n-m && !a.empty() && !b.empty()){
        if(*a.rbegin() == *b.rbegin()){
            auto ita = a.end(), itb = b.end(); 
            ita--; itb--; 
            a.erase(ita); 
            b.erase(itb);
        } else {
            auto itb = b.end();
            itb--;
            int piso = *itb / 2, teto = (*itb + 1)/2; 
            b.erase(itb);
            b.insert(piso); b.insert(teto);
            qntd++;
        }
    }

    if(a == b) return true; 
    return false;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        if(solve()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}