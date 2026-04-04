#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/problemset/problem/2184/D

const int N = 31; 
const int K = 61;
int dp[N][K];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // eu quero que dp[n][k] calcule quantos caras no intervalo de 2^n até 2^{n+1}-1 são 
    // tais que seja possível fazer com exatamente k
    // a minha recorrencia eh que dp n,k = dp n-1, k-1 + dp n-1, k-2
    for(int i=0;i<N;i++){
        if(i == 0) dp[i][1] = 1;
        else dp[i][1] = 0;
    } 
    for(int i=0;i<N;i++){
        if(i == 1) dp[i][2] = 1;
        else dp[i][2] = 0;
    }
    dp[1][3] = 1;
    for(int i=2;i<N;i++){
        for(int j=3;j<K;j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j-2];
        }
    }
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        k = min(k, (int)60);
        int log = log2(n);
        // printf("o valor de log é %lld\n", log);
        int sum = 0; 
        for(int log1 = log-1; log1 >=0 ; log1--){
            for(int i=1;i<=k;i++){
                // printf("estou adicionando aos valores que ela pode dp[%lld][%lld] = %lld.\n", log1, i, dp[log1][i]);
                sum += dp[log1][i];
            }
        }

        if(k >= log+1) sum++;

        cout << n - sum << endl;
    }
    
    return 0;
}