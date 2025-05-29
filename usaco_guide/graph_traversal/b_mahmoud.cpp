#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> grafo;
vector<int> cor;

void dfs(int v) {
    for(auto u:grafo[v]){
        if(cor[u] == -1){
            cor[u] = 1 - cor[v];
            dfs(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    grafo.resize(n);
    cor.resize(n,-1);
    for(int i=0;i<n-1;i++){
        int a, b; cin >> a >> b;
        a--; b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    int contador_1 = 0, contador_2 = 0;
    cor[0] = 0;
    dfs(0);
    for(int i=0;i<n;i++){
        if(cor[i] == 1) contador_1++;
        else if(cor[i] == 0) contador_2++;
    }
    long long ans = (long long) (contador_1 - 1) * (contador_2 - 1);
    cout << ans << endl;
    

    return 0;
}