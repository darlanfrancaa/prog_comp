#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        ll n, s,x; cin >> n >> s >> x; 
        vector<ll> valores(n+1), pref(n+2,0);
        for(int i=1;i<=n;i++){
            cin >> valores[i];
            pref[i] = pref[i-1] + valores[i];
        }
        ll ans = 0; 
        map<ll,int> mapa; // o mapa vai armazenar as prefix-sum que são válidas no momento  
        int last = 1; // isso vai salvar o último cara adicionado no mapa
        for(int i=1;i<=n;i++){
            if(valores[i] > x) {
                mapa.clear();
                last = i+1;
            }
            else if(valores[i] == x){
                while(last <= i){
                    mapa[pref[last-1]]++; // só iremos colocar no mapa quando tiver um x, pois, caso contrário, poderíamos adicionar no mapa somas que não têm máximo x
                    last++; // movemos a última posição que foi adicionada
                }
            }
            ans += mapa[pref[i]-s];
        }
        cout << ans << "\n";
        
        
    }
    return 0;
}