#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> moedas(n);
    for(auto &num: moedas) cin >> num; 
    map<int,int> mapa; 
    mapa[0] = 1;
    for(auto moeda : moedas){
        map<int,int> temp = mapa;
        for(auto [k,v] : temp){
            mapa[k+moeda]++;
        }
    }
    int contador = 0; 
    for(auto [k,v]: mapa ) {
        if (k!= 0) {
            contador++;
        } 
    }
    cout << contador << endl;
    for(auto [k,v]: mapa ) {
        if (k!= 0) {
            cout << k << " ";
        } 
    }
    return 0;
}