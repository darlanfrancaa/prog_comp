#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
vector<int> adj[MAXN];
int n,m;
int dp1[MAXN],ans[MAXN];    

void dfs1(int node = 1, int p = 0){
    dp1[node] = 1;
    for(int v: adj[node]){
        if(v != p){ 
            dfs1(v, node);
            dp1[node] = dp1[node] * (dp1[v] + 1) % m;
        }
    }
}

void dfs2(int node = 1, int p = 0, int ans_p = 1){
    ans[node] = (dp1[node] * ans_p) % m;
    // então eu tenho que passar pra cada filho de node, o produto tirando ele
    vector<int> filhos;
    for(auto v: adj[node]){ 
        if(v!=p){ 
            filhos.push_back(v);
        }
    }
    int tam = filhos.size(); 
    if (tam == 0) return;
    vector<int> preffix(tam);
    vector<int> suffix(tam);
    preffix[0] = (dp1[filhos[0]] + 1) % m; 
    for(int i=1;i<tam;i++){
        int v = filhos[i]; 
        preffix[i] = preffix[i-1] * ((dp1[v] + 1) % m) % m;
    }
    suffix[tam-1] = (dp1[filhos[tam-1]] + 1) % m;
    for(int i = tam-2;i>=0;i--){
        int v = filhos[i];
        suffix[i] = suffix[i+1] * ((dp1[v] + 1) % m) % m;
    }
    for(int i=0;i<tam;i++){
        int v = filhos[i];
        int ans_node = 1; 
        if(i > 0){
            ans_node = ans_node * preffix[i-1] % m;
        } 
        if(i < tam-1){
            ans_node = ans_node * suffix[i+1] % m;
        }
        ans_node = (ans_node * ans_p ) % m; 
        dfs2(v,node, (ans_node+1)%m);
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >>  m;
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(); 
    dfs2();     
    for(int i=1;i<=n;i++){
        cout << ans[i] << "\n"; 
    }
    return 0;
}