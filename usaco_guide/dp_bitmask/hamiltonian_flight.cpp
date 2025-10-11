#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

const int MAXN = 20;

int dp[MAXN][1<<MAXN];
// dp[i][S] representa o número de caminhos que visita todas as cidades de S e termina na cidade i;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b;
        a--;b--;
        adj[b].push_back(a);
    }
    dp[0][1] = 1;
    for(int mask = 2; mask < (1<<n); mask++){
        if((mask & (1<<0)) == 0) continue;
        if((mask & (1 << (n-1))) && mask != ((1<<n) - 1)) continue;
        for(int i=0;i<n;i++){
            if(!(mask && (1<<i))) continue;
            for(auto v: adj[i]){
                if(mask & (1<<v)) dp[i][mask] = (dp[i][mask] + dp[v][mask ^ (1 << i)]) % MOD;
            }
        }
    }
    cout << dp[n-1][(1 << n)- 1];
    return 0;
}