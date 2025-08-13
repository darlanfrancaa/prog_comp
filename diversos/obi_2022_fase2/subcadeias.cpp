#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    string s; 
    cin >> n >> s; 
    int maximo_impar = 1;
    int maximo_par = 0; 
    for(int i=0;i<n;i++){
        int l = i, r = i;
        while(l>= 0 && r<n && s[l]==s[r]){
            maximo_impar = max(maximo_impar, r-l+1);
            l--; r++;
        }
        l = i, r = i+1;
        while(l>=0 && r < n && s[l]==s[r]){
            maximo_par = max(maximo_par, r-l+1);
            l--; r++;
        }
    }
    cout << max(maximo_impar, maximo_par) << endl;


    return 0;
}