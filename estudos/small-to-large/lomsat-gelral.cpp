#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

const int MAXN = 1e5;
array<int, MAXN> color; 
array<int, MAXN> ans; 
vector<int> adj[MAXN];

map<int,int> col_count[MAXN]; // {3:5}
map<int,int> sum_occur[MAXN]; // {5:3} {5:7} {5:10}  

void dfs(int node, int p){
    col_count[node][color[node]] += 1;
    sum_occur[node][1] += color[node]; 

    for(int i: adj[node]){
        if(i == p) continue;
        dfs(i, node);

        if(col_count[node].size() < col_count[i].size()){
            col_count[node].swap(col_count[i]);
            sum_occur[node].swap(sum_occur[i]);
        }

        for(auto [col, cnt]: col_count[i]){
            if(col_count[node].count(col)){
                sum_occur[node][col_count[node][col]] -= col;
            }
            col_count[node][col] += cnt;
            sum_occur[node][col_count[node][col]] += col;
        }
    }
    ans[node] = sum_occur[node].rbegin()->second;
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    for(int i=0; i<n;i++) cin >> color[i];
    for(int i=0; i<n-1;i++){
        int u,v; cin >> u >> v; 
        u--;v--; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,0);
    for(int i=0;i<n;i++) cout << ans[i] << " ";
    return 0;
}