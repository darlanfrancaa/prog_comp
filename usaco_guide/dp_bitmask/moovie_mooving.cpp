#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    freopen("movie.in", "r", stdin);
    freopen("movie.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, l; cin >> n >> l; 
    int M = (1 << n);
    vector<int> duracao(n);
    vector<vector<int>> filmes(n);
    vector<int> dp(M,-1);
    for(int i=0;i<n;i++){
        cin >> duracao[i];
        int c; cin >> c;
        for(int j=0;j<c;j++){
            int f; cin >> f; 
            filmes[i].push_back(f);
        }
    }

    for (int i = 0; i < n; i++) {
        if (binary_search(filmes[i].begin(), filmes[i].end(), 0)) {
            dp[1 << i] = max(dp[1 << i], duracao[i]);
        }
    }
    
    for(int mask = 1; mask < M; mask++){
        if (dp[mask] == -1) continue;    

        for(int i = 0; i < n;i++){
            if((mask & (1 << i))) continue; 
            int prev_time = dp[mask];
            auto it = upper_bound(filmes[i].begin(), filmes[i].end(), prev_time);
            if(it == filmes[i].begin()) continue;
            else {
                it--;
                int comeco_filme = *it;
                int fim_filme = comeco_filme + duracao[i];
                int next_mask = mask | (1 << i);
                dp[next_mask] = max(dp[next_mask],fim_filme);
            }
                
        }
        
    }
    int ans = LLONG_MAX; 
    for(int mask = 1; mask < M; mask++){
        if(dp[mask] >= l) ans = min(ans, (int)__builtin_popcount(mask));
    }
    if(ans == LLONG_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}