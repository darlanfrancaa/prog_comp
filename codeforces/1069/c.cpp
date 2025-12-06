#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

void solve(){ 
    string s,t; 
    cin >> s >> t; 
    vector<int> count_s(26,0), count_t(26,0);
    // cout << "estou dentro de um caso\n";
    for(char c: s) count_s[c - 'a']++;
    for(char c: t) count_t[c - 'a']++;

    vector<int> sobras(26,0);
    for(int i=0;i<26;i++){
        if(count_t[i] < count_s[i]){
            cout << "Impossible\n"; 
            return;
        }
        sobras[i] = count_t[i] - count_s[i];
    }
    int n = s.length(); 

    string resto = ""; 
    for(int i=0;i<26;i++){
        while(sobras[i] > 0){
            resto += (char)('a' + i);
            sobras[i]--;
        }
    }

    string ans = "";
    int pont_resto = 0 , pont_s = 0;
    // cout << resto << "\n" << s << "\n";

    while(pont_resto < resto.length() || pont_s < s.length()){
        if(pont_s == s.length()) {
            ans += resto[pont_resto++];
            continue;
        }
        if(pont_resto == resto.length()) {
            ans += s[pont_s++];
            continue;
        }
        char comeco_resto = resto[pont_resto];
        char comeco_s = s[pont_s];
        if(comeco_s <= comeco_resto){
            ans += comeco_s;
            pont_s++;
        } else {
            ans += comeco_resto;
            pont_resto++;
        }
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