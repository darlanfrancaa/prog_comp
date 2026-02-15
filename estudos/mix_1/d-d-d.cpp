#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/contest/2109/problem/D

struct T{
    int vertice;
    int dist; 
    int par;
};

void solve(){
    int n,m,l; cin >> n >> m >> l; 
    int min_impar = LLONG_MAX; 
    int sum = 0; 
    for(int i=0;i<l;i++){
        int val; cin >> val; 
        sum += val; 
        if(val % 2 == 1) min_impar = min(min_impar, val);
    }
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b; 
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> dp(n+1, vector<int> (2, LLONG_MAX));
    queue<T> q; 
    q.push({0,0,0});
    vector<vector<bool>> visitado(n+1, vector<bool> (2, false)); 
    dp[0][0] = 0;
    visitado[0][0] = true;
    while(!q.empty()){
        auto [v, distancia, paridade] = q.front(); q.pop();
        // printf("estou no vértice %lld com a distancia atual %lld e paridade %lld\n", v, distancia, paridade);
        // printf("atualizei o valor de dp[%lld][%lld] para %lld e coloquei vistado[%lld][%lld] com true\n", v, paridade, dp[v][paridade], v,paridade);
        int next_par = (paridade + 1) % 2;
        for(auto node: adj[v]){
            if(visitado[node][next_par]) continue;
            dp[node][next_par] = min(dp[node][next_par],distancia+1);
            q.push({node, distancia + 1, next_par});
            visitado[node][next_par] = true;
        }
    }
    int paridade_soma = sum % 2; 
    // if(min_impar != LLONG_MAX)
    // printf("o valor de sum é %lld e o valor de sum - min é %lld\n", sum, sum - min_impar);
    for(int i=0;i<n;i++){
        // eu quero responder pro valor i
        if(dp[i][paridade_soma] <= sum) {
            // printf("para o vértice %lld e paridade %lld temos o valor de %lld\n", i, paridade_soma, dp[i][paridade_soma]);
            cout << 1;
        } else if(min_impar != LLONG_MAX && dp[i][1 - paridade_soma] <= sum - min_impar ){
            // printf("para o vértice %lld e paridade %lld temos o valor de %lld\n", i, paridade_soma, dp[i][paridade_soma]);
            cout << 1;
        } else cout << 0;
    }
    cout << endl;
 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}