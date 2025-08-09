#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        string palavra; cin >> palavra; 
        if(n==3){
            if(palavra[0] == palavra[1] || palavra[1] == palavra[2]) cout << "yes" << endl; 
            else cout << "no" << endl;
            continue; 
        }
        map<char,int> mapa; 
    for(int i=1;i<n-1;i++){
        mapa[palavra[i]]++;
    }
    bool poss = false; 
    for(auto [k,v]: mapa){
        if(v >= 2) poss = true;
    }
    if(!poss){
        int comeco = palavra[0];
        int fim = palavra[n-1];
        for(int i=1;i<n-1;i++){
            if(palavra[i] == comeco || palavra[i] == fim) poss = true; 
        }
    }
    if(poss) cout << "yes" << endl; 
    else cout << "no" << endl;
    
    }
    return 0;
}