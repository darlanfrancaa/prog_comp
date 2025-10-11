#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main(){
    int n, m; cin >> n >> m; 
    vector<int> v_n(n);
    vector<int> v_m(m);
    for(auto &a: v_n) cin >> a; 
    for(auto &a: v_m) cin >> a; 
    int MAX_M = (1<<m);
    // vamos armazena em cada mask a quantidade de caras que ela conseguiu chegar e o valor que está sobrando nela para 
    // pagar o próximo cara
    vector<pii> dp(MAX_M,{-1,0}); // o par vai armazenar {em qual caras paramos, soma restante para o próximo cara}
    dp[0] = {0,0};
    for(int mask = 1; mask < MAX_M; mask++){
        for(int i=0;i<m;i++){
            if(mask & (1<<i)){
                int prev = mask ^ (1 << i);
                if(dp[prev].first == -1) continue;
                int soma_atual = dp[prev].second + v_m[i];
                int valor_prox_cara = v_n[dp[prev].first];
                if(soma_atual < valor_prox_cara){
                    dp[mask].first = dp[prev].first;
                    dp[mask].second = soma_atual;
                } else if(soma_atual == valor_prox_cara) {
                    dp[mask].first = dp[prev].first + 1;
                    dp[mask].second = 0;
                }
            }
        }
        if(dp[mask].first == n){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;

}