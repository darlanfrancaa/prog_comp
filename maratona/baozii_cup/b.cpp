#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAX = 4*1e5;

// problem link: 

int n;
vector<int> g[MAX];
vector<int> gi[MAX];
int vis[MAX];
stack<int> S;
int comp[MAX];
int parit[MAX];

void bfs(int k){
    if(parit[comp[k]] != 0) return;
    queue<int> f;
    f.push(k);
    parit[k] = 2;
    int paritatual = 1;

    while(!f.empty()){

        int next = f.front();
        f.pop();
        for(auto j : g[next]){
            if(comp[j] != comp[k]) continue;
            if(parit[j] == 0){
                parit[j] = paritatual;
                f.push(j);
            }
            else if(parit[j] != paritatual){
                parit[comp[k]] = 1;
            }
        }

        paritatual++;
        if(paritatual == 3) paritatual = 1;
    }
}

void dfs(int k){
    vis[k] = 1;
    for(int i = 0; i < (int) g[k].size(); i++)
        if(!vis[g[k][i]]) dfs(g[k][i]);
    S.push(k);
}

void scc(int k, int c){
    vis[k] = 1;
    comp[k] = c;
    for(int i = 0; i < (int) gi[k].size();i++)
        if(!vis[gi[k][i]]) scc(gi[k][i], c);
}

void kosaraju(){
    for(int i = 0; i < n; i++) vis[i] = 0;
    for(int i = 0; i < n; i++) if(!vis[i]) dfs(i);
    for(int i = 0; i < n; i++) vis[i] = 0;
    while(S.size()) {
        int u = S.top();
        S.pop();
        if(!vis[u]) scc(u,u);
    }
}

void solve(){

    int m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        gi[b].push_back(a);
    }

    kosaraju();

    for(int i = 0; i < n; i++){
        bfs(i);
    }

    for(int i = 0; i< n;i++){
        cout << parit[comp[i]] % 2;
    }
    cout << "\n";


    for(int i = 0; i < n; i++){
        g[i].clear();
        gi[i].clear();
        if(S.size()) S.pop();
        vis[i] = 0;
        comp[i] = 0;
        parit[i] = 0;
    }
}

signed main() {
    //ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}