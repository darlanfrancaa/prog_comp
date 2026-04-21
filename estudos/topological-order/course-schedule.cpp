#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1757

const int N = 1e5+10;
int n;
vector<int> adj[N];
vector<int> adj_rev[N];
vector<int> ans;
int degout[N];
priority_queue<int> pq;

void solve(){
    int curr = n;
    while(!pq.empty()){
        int v = pq.top(); pq.pop();
        ans[curr] = v;
        curr--;
        for(auto node: adj_rev[v]){
            degout[node]--;
            if(degout[node] == 0) pq.push(node);
        }
    }

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int m; cin >> n >> m; 
    ans.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        degout[a]++;
        adj_rev[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(degout[i] == 0) pq.push(i);
    }

    solve(); 
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }

    
    return 0;
}