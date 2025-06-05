#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
int n;
vector<vector<int>> adj;
vector<int> ans;

void dfs(int node){
    ans[node] = 1;
    for(int filho: adj[node]){
        dfs(filho);
        ans[node] += ans[filho];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    ans.resize(n);
    adj.resize(n,vector<int>());
    for(int i=1;i<=n-1;i++){
        int v; cin >> v;
        v--;
        adj[v].push_back(i);
    }
    dfs(0);
    for(int i=0;i<n;i++){
        cout << ans[i] - 1 << " ";
    }
    return 0;
}