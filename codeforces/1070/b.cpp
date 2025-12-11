#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; string s; 
        cin >> n >> s; 
        int maximo = 0;
        string nova = "";
        nova += s; nova += s; 
        // cout << nova << "\n"; 
        int it = 0; 
        while(it < 2*n){
            if(nova[it] == '0'){
                int c = 0;
                while(it < 2*n && nova[it] == '0'){
                    c++; 
                    it++;
                }
                // printf("o contador atual foi %lld\n", c);   
                maximo = max(c,maximo);
            } else while(it < 2*n && nova[it] != '0') it++;
        }
        cout << maximo << '\n';
    }
    return 0;
}