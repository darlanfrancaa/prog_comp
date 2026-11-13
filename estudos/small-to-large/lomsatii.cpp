#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 2e5+10;

// problem link: 

int n;
map<int,int> qtd[MAXN];
int mx[MAXN], soma[MAXN], idx[MAXN], ans[MAXN], cor[MAXN];
vector<int> adj[MAXN];

// adicionar em idx[b] o valor c q vezes e atualizar o valor de idx
void add(int b, int c, int q){
    int k = (qtd[b][c] += q); 
    if (k > mx[b]) {
        mx[b] = k;
        soma[b] = c;
    } else if (k == mx[b]) soma[b] += c;
}

void dfs(int u, int p){
    idx[u] = u;
    add(u, cor[u], 1);
    for(auto v: adj[u]) if(v != p){
        dfs(v,u);
        int a = idx[u], b = idx[v];
        if(qtd[a].size() < qtd[b].size()) swap(a,b);
        for(auto [c,k] : qtd[b]) add(a,c,k);
        qtd[b].clear();
        idx[u] = a;
    }
    ans[u] = soma[idx[u]];
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n; 
    for(int i=0; i<n;i++) cin >> cor[i];
    for(int i=0;i<n-1;i++){
        int a, b; cin >> a >> b; 
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0,-1);
    for(int i=0;i<n;i++) cout << ans[i] << " ";
    return 0;
}