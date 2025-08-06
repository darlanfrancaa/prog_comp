#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

const int MAXN = 20; 

ll dp[1<< MAXN][MAXN];
vector<int> deg_in[MAXN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b; 
        deg_in[--b].push_back(--a);
    }
    dp[1][0] = 1;
    for(int s = 2; s < (1 << n); s++){
        if((s & 1) == 0) continue; // tem que comecar pela primeira cidade
        if(s & (1 << (n-1)) && s != ((1 << n) - 1)) continue; // se tem a ultima cidade, então tem que que ter todas as cidades
        for(int fim = 0; fim < n ; fim++){
            if((s & (1 << fim)) == 0) continue; // verifica se o conjunto tem a cidade que esta terminando
            int conj_ant = s - (1 << fim); // tira a cidade do conjunto
            for(int j : deg_in[fim]){
                dp[s][fim] += dp[conj_ant][j]; 
                dp[s][fim] %= MOD;
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1];
    return 0;
}