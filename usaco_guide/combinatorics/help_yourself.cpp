#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> posicao(2*n+1,0);
    for(int i=0;i<n;i++){
        int x, y; cin >> x >> y; 
        posicao[x]++;
        posicao[y]--;
    }
    vector<ll> potencias(n);
    potencias[0] = 1;
    for(int i = 1;i <= n-1;i++) potencias[i] = potencias[i-1] * 2 % MOD;
    int segmentos_abertos = 0;
    ll ans = 0;
    for(int i = 1;i <= 2*n; i++){
        segmentos_abertos += posicao[i]; //prefix sum que calcula o numero de segmentos naquela posicao
        if (posicao[i] == 1){
            ans = ((ans + potencias[n - segmentos_abertos]) % MOD );
        }
    }
    cout << ans << endl;
    return 0;
}