#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://atcoder.jp/contests/dp/tasks/dp_v


const int N = 100005;
vector<int> adj[N];
int dp[N]; 
int n, m;

void dfs1(int u, int p){
    dp[u] = 1; 
    for(int v:adj[u]){
        if(v == p) continue;
        dfs1(v,u);
        dp[u] = (dp[u] * (dp[v] + 1)) % m;
    }
}

void dfs2(int u, int p, int valor){
    vector<int> filhos;
    for(int v: adj[u]){
        if(v != p) filhos.push_back(v);
    }
    int k = filhos.size();
    vector<int> pref(k,1), suff(k,1);

    if(k > 0){
        for(int i=0;i<k;i++){
            pref[i] = suff[i] = (dp[filhos[i]] + 1) % m;
        }
        for(int i=1; i<k;i++) pref[i] = (pref[i] * pref[i - 1]) % m;
        for (int i = k - 2; i >= 0; i--) suff[i] = (suff[i] * suff[i + 1]) % m;
    }

    dp[u] = (dp[u] * valor) % m;
    for(int i=0;i<k;i++){
        int v = filhos[i];
        int prod = 1; 
        if(i > 0) prod = (prod * pref[i-1]) % m;
        if(i < k-1) prod = (prod * suff[i+1]) % m;
        int next_val = ((valor * prod) % m + 1) % m;
        dfs2(v,u,next_val);
    }
}



signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; 
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0,1);
    for(int i =1;i<=n;i++){
        cout << dp[i] << endl;
    }
    return 0;
}