#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: 

vector<int> et, tin, tout; 
vector<bool> visited;
int timer = 0; 
unordered_map<int, vector<int>> pos; 
void dfs(int v, vector<vector<int>> &adj){
    visited[v] = true;
    et.push_back(v);
    tin[v] = timer++; 
    for(auto node: adj[v]){
        if(!visited[node]) dfs(node,adj);
    }
    tout[v] = timer-1; 
}

int query(int x, int val){
    int ans = 0; 
    auto it = pos.find(val);
    int l = tin[x], r = tout[x];
    if(it != pos.end()){
        const auto& vetor = it->second; 
        auto left = lower_bound(vetor.begin(), vetor.end(), l);
        auto right = upper_bound(vetor.begin(), vetor.end(), r);
        ans = right - left;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    tin.resize(n); tout.resize(n); visited.resize(n);
    vector<int> v(n); 
    for(auto &val: v) cin >> val; 
    vector<vector<int>> adj(n, vector<int>());
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b; 
        a--;b--;
        adj[a].push_back(b);
    }
    dfs(0, adj);
    int k = et.size();
    for(int i=0;i<k;i++){
        pos[v[et[i]]].push_back(i);
    }
    for(int i=0;i<q;i++){
        int x, val; cin >> x >> val; 
        x--;
        // quero fazer uma query em tin[x], tout[x] de quantos valores val existem
        cout << query(x, val) << "\n";
    }

    return 0;
}