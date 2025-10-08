#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main(){
    int n, m; cin >> n >> m; 
    int adj[16][16];
    map<int,int> flip;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b; 
        a--;b--;
        adj[a][b] = 1; 
        adj[b][a] = 1;
    }
    // flip vai armazenar o número operações que precisam ser feitas para transformar uma certa mask
    // em um clique
    for(int mask = 0; mask < (1<<n);  mask++){
        for(int i =0;i<n;i++){
            for(int j= i+1;j<n;j++){
                if((mask & (1<<i)) && (mask & (1<<j))){
                    if(adj[i][j]){
                        flip[mask]++; 
                    } else{
                        flip[mask]--;
                    }
                }
            }
        }
    }
    vector<int> dp((1<<n));
    // a nossa transição da dp será: dado uma mask, para cada subconjunto dessa mask eu vou calcular 
    // o custo de transformar esse subconjunto em um clique e somar com o custo de transformar o restante 
    // que já foi calculado
    int max_edges = n * (n - 1) / 2;
    dp[0] = max_edges - m; 
    for(int mask = 1; mask < (1<<n); mask++){
        dp[mask] = LLONG_MAX;
        for(int submask = mask; submask; submask = (submask - 1) & mask){
            dp[mask] = min(dp[mask], dp[mask & (~submask)] + flip[submask]);
        }
        printf("para a mascara %lld, temos o valor %lld\n", mask, dp[mask]);
    }
    cout << dp[(1<<n) - 1] << "\n";
}