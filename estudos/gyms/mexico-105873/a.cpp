#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/gym/105873/problems

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s; 
    int t; cin >> t; 
    int n = s.size();
    while(t--){
        string test; cin >> test; 
        if(test.size() % n != 0) {
            cout << "No\n";
            continue; 
        }
        int i=0; 
        bool flag = true;
        while(i < test.size()){
            for(int j=0; j<n;j++){
                if(test[i] != s[j]) flag = false;
                i++;
            }
        }
        if(flag) cout << "Yes\n";
        else cout << "No\n"; 
    }
    return 0;
}
