#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

// problem link: 
int n; 
vector<int> adj[MAXN];
int sz[MAXN], f[MAXN], ans[MAXN];

void dfs1(int u, int p){
    sz[u] = 1;
    for(auto v: adj[u]){
        if(v != p) {
            dfs1(v,u);
            sz[u] += sz[v]; // calcula o size
            f[u] += f[v]; // adiciona o valor da f de cada filho
        }
    }
    f[u] += sz[u]; // adiciona na f o valor do size da primerira operação
    return;
}

// vou trocar a raiz de u para cada filho dele
void dfs2(int u, int p){
    for(int v: adj[u]) if (v != p){
        ans[v] = ans[u] + n - 2 * sz[v];
        dfs2(v,u);
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b; 
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(0,-1);
    ans[0] = f[0];
    dfs2(0,-1);
    cout << *max_element(ans, ans + n) << endl;

    return 0;
}