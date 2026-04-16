#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
// problem link: https://www.spoj.com/problems/TOPOSORT/

const int N = 1e5+10;
vector<int> adj[N];
int in_degree[N];
vector<int> ans;

void kahn(int n){
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i=1;i<=n;i++){
        if(in_degree[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        int u = q.top(); q.pop(); 
        ans.push_back(u);
        for(int v: adj[u]){
            in_degree[v]--; 
            if(in_degree[v] == 0) q.push(v);
        }
    }

    if(ans.size() < n){
        cout << "Sandro fails.\n"; 
    } else {
        for(auto val: ans){
            cout << val << " ";
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }
    kahn(n);
    return 0;
}