#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t>0){
        t--;
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int contador_1 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1') contador_1++;
        }  
        int contador_0 = n - contador_1;
        bool ok = true;
        int num = n/2 - k;
        if(num<0 || num > contador_0 || num > contador_1)ok = false;
        else if( (contador_0 - num ) % 2 != 0) ok = false;
        cout << (ok ? "YES" : "NO") << endl;

        
    }
    return 0;
}