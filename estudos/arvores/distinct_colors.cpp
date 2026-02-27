#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1139
const int N = 2e5 + 10; 
vector<int> adj[N]; 
set<int> dist_cor[N];
int cor[N];
bool visitado[N];
int ans[N];

void dfs(int v){
    dist_cor[v].insert(cor[v]);
    visitado[v] = true; 
    for(auto node: adj[v]){
        if(!visitado[node]){
            dfs(node);
            if(dist_cor[node].size() > dist_cor[v].size()) swap(dist_cor[node], dist_cor[v]);
            for(auto vertice: dist_cor[node]) dist_cor[v].insert(vertice); // inserindo o menor no maior
        }
    }
    ans[v] = dist_cor[v].size(); 
    return; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    for(int i=1;i<=n;i++) cin >> cor[i];
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    return 0;
}