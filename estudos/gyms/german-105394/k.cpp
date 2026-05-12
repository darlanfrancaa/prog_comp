#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/gym/105394/problem/K

string change(string s, char op){ 
    if(op == 'h'){
        reverse(s.begin(), s.end());
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'q') s[i] = 'p';
            else if(s[i] == 'p') s[i] = 'q';
            else if(s[i] == 'b') s[i] = 'd';
            else if(s[i] == 'd') s[i] = 'b';
        }
    } else if(op == 'r'){
        reverse(s.begin(), s.end());
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'q') s[i] = 'b';
            else if(s[i] == 'b') s[i] = 'q';
            else if(s[i] == 'p') s[i] = 'd';
            else if(s[i] == 'd') s[i] = 'p';
        }
    } else if (op == 'v'){
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'q') s[i] = 'd';
            else if(s[i] == 'b') s[i] = 'p';
            else if(s[i] == 'p') s[i] = 'b';
            else if(s[i] == 'd') s[i] = 'q';
        }
    }
    return s;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s, ops; cin >> s >> ops; 
    int qtd_h = 0, qtd_v = 0, qtd_r = 0; 
    for(int i=0;i<ops.size();i++){
        char op = ops[i];
        if(op == 'h') qtd_h ^= 1;
        if(op == 'v') qtd_v ^= 1;
        if(op == 'r') qtd_r ^= 1;
    }
    string ans = s;
    if(qtd_h) ans = change(ans,'h');
    if(qtd_v) ans = change(ans,'v');
    if(qtd_r) ans = change(ans,'r');
    cout << ans;
    return 0;
}