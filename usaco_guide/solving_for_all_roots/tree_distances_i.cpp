#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 2e5+1;

vector<int> graph[MAXN];
int primeiro[MAXN], segundo[MAXN], ans[MAXN];

void dfs1(int node = 1, int p = 0){
    for(int v : graph[node]){
        if(v != p){
            dfs1(v, node);
            if(primeiro[v] + 1 > primeiro[node]){
                segundo[node] = primeiro[node];
                primeiro[node] = primeiro[v]+1;
            } else if(primeiro[v] + 1 > segundo[node]){
                segundo[node] = primeiro[v] + 1;
            }
        }
    }
}

void dfs2(int node = 1, int p = 0, int melhor_caminho_pai = 0){
    ans[node] = max(melhor_caminho_pai, primeiro[node]);
    for(int v: graph[node]){
        if(v != p){
            if(primeiro[v] + 1 == primeiro[node]) dfs2(v, node, max(melhor_caminho_pai, segundo[node])+1); 
            else dfs2(v, node, ans[node] + 1);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n ; cin >> n; 
    for(int i=1;i<n;i++){
        int a,b; cin >> a >> b; 
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs1(); 
    dfs2(); 
    for(int i=1; i<= n;i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}