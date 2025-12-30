#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1696

const int MAXN = 510;

int n,m,k; 
vector<int> adj[MAXN];
vector<int> match; 
vector<bool> used;

bool try_kuhn(int v){
    if(used[v]) return false; 
    used[v] = true; 
    for(int to: adj[v]){
        if(match[to] == -1 || try_kuhn(match[to])){
            match[to] = v;
            return true;
        }
    }

    return false;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0;i<k;i++){
        int u,v; cin >> u >> v; 
        u--;v--; 
        adj[u].push_back(v);
    }
    match.assign(m,-1);
    int ans = 0;
    for(int i=0;i<n;i++){
        used.assign(n, false);
        if(try_kuhn(i)) ans += 1; 
    }
    cout << ans << "\n";
    for(int i=0;i<m;i++){
        if(match[i] != -1){
            cout << match[i]+1 << " " << i+1 << '\n';
        }
    }
    return 0;
}