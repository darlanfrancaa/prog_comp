#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

string next_string(string s){
    bool sonove = true;
    for(int i=s.size()-1;i>=0;--i){
        if(s[i] == '9'){
            s[i] = '0';
        } else {
            s[i]++;
            sonove = false; 
            break;
        }
    }
    if(sonove) {
        s = "1" + s;
    }
    return s;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    string s;
    for(int i=0;i<n;i++){
        string a; cin >> a; 
        s += a;
    }
    for(int tamanho = 1; tamanho <= n; ++tamanho){
        string comeco, proxima; 
        for(int i=0;i<tamanho;i++){
            comeco += s[i];
        }
        proxima = comeco;
        string curr; 

        for(int i=0;i<n;i++){
            curr += s[i];
            if(curr == proxima){
                curr = "";
                proxima = next_string(proxima);
            }
        }
        if(curr == ""){
            cout << comeco << "\n";
            return 0;
        }
    }
    return 0;
}