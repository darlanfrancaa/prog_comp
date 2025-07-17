#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> dias(n,0);
        for(auto &dia: dias) cin >> dia;
        bool terminou_viagem = false;
        int contador_dias = 0, contador_viagens = 0;
        for(int i=0;i<n;i++){
            if(contador_dias == k){
                contador_dias = 0; contador_viagens++; continue;
            }
            else if(dias[i] == 0) contador_dias++;
            else if(dias[i] == 1) contador_dias = 0;
        }
        if(contador_dias == k) contador_viagens++;
        cout << contador_viagens << endl;
    }
    return 0;
}