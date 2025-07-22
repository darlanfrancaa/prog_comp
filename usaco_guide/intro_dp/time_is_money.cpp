#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, c; cin >> n >> m >> c; 
    vector<int> vetor(n);
    for(auto &num:vetor) cin >> num;
    vector<vector<int>> grafo(n,vector<int>());
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b; 
        a--; b--;
        grafo[a].push_back(b);
    }
    vector<vector<int>> dp(n,vector<int>(503,-1));
    dp[0][0] = 0;
    for(int t=0;t<502;++t){
        for(int u=0;u<n;++u){
            if(dp[u][t]==-1) continue;

            for(int v: grafo[u]){
                dp[v][t+1] = max(dp[v][t+1], dp[u][t] + vetor[v]);
            }
        }
    }
    ll maximo = 0;
    for(int i=0;i<503;++i){
        if(dp[0][i] != -1){
            ll atual = (ll)dp[0][i] - (ll)c*i*i;
            maximo = max(maximo, atual);
        }
    }
    
    cout << maximo << endl;
    return 0;
}