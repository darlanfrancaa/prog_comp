#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

const int N = 2e5 + 10;
int n, m;
vector<int> adj[N];
int degin[N];
pair<int,int> rest[N];
bool impossible = false;

int ans[N];

struct Compare{
    bool operator()(int a, int b) const {
        return rest[a].second > rest[b].second;
    }
};

priority_queue<int, vector<int>, Compare> pq;

void solve(){
    vector<int> topo;
    queue<int> q;
    
    for(int i = 1; i <= n; i++){
        if(degin[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(auto v : adj[u]){
            degin[v]--;
            if(degin[v] == 0) q.push(v);
        }
    }
    
    if(topo.size() != n) {
        impossible = true;
        return;
    }

    for(int u : topo){
        for(auto v : adj[u]){
            rest[v].first = max(rest[v].first, rest[u].first + 1);
        }
    }

    for(int i = n - 1; i >= 0; i--){
        int u = topo[i];
        for(auto v : adj[u]){
            rest[u].second = min(rest[u].second, rest[v].second - 1);
        }
    }

    vector<vector<int>> lazy(n + 2);
    for(int i = 1; i <= n; i++){
        if(rest[i].first > rest[i].second || rest[i].first > n || rest[i].second < 1){
            impossible = true;
            return;
        }
        int start_time = max(1LL, rest[i].first);
        if(start_time <= n) lazy[start_time].push_back(i);
    }

    for(int curr = 1; curr <= n; curr++){
        for(auto v : lazy[curr]){
            pq.push(v);
        }
        
        if(pq.empty()){
            impossible = true;
            return;
        }
        
        int v = pq.top();
        pq.pop();
        
        if(rest[v].second < curr){
            impossible = true;
            return;
        }
        ans[v] = curr;
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m; 
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; 
        adj[a].push_back(b);
        degin[b]++;
    }

    for(int i = 1; i <= n; i++){
        int li, ri; cin >> li >> ri; 
        rest[i] = {li, ri};
    }

    solve();

    if(impossible){    
        cout << "No\n";
        return 0;
    }
    
    cout << "Yes\n";
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}