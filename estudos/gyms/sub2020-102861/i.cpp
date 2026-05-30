#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/gym/102861/problem/I
const int N = 1e5+10;
vector<int> adj[N];

int dp0[N], dp1[N];
// dp0 vai salvar o caso em que ele só resolve os dos filhos e que não é marcado
// dp1 resolve o caso em que ele é marcado e deixou faltando para algum dos filhos

void compute(int v, int p){
    vector<int> filhos; 
    for(int u: adj[v]){
        if(u == p) continue;
        filhos.push_back(u);
        compute(u, v);
    }

    if(filhos.empty()){
        dp0[v] = 1; 
        dp1[v] = 1; 
        return;
    }

    int k = filhos.size();
    vector<int> pref(k+1,1);
    vector<int> suff(k+1,1);

    for(int i=0;i<k;i++){
        pref[i + 1] = (pref[i] * dp0[filhos[i]]) % MOD;
    }

    for(int i = k-1; i>=0;i--){
        suff[i] = (suff[i+1] * dp0[filhos[i]]) % MOD;
    }

    int p0 = pref[k];
    int s = 0; 
    for(int i=0;i<k;i++){
        int u = filhos[i];
        int prod = (pref[i] * suff[i+1]) % MOD;
        int curr = (prod * dp1[u]) % MOD;
        s = (s + curr) % MOD;
    }

    dp1[v] = s; 
    dp0[v] = (s + p0) % MOD;
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n-1;i++){
        int u; cin >> u; 
        int v = i+1;
        u--; v--;
        adj[u].push_back(v); 
        adj[v].push_back(u);  
    }

    compute(0,-1);
    cout << dp0[0];
    return 0;
}