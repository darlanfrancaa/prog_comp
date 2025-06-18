#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
int diametro = 0;
 
int dfs(int node, int pai){
    int max1 = 0, max2 = 0;
    for(auto k: adj[node]){
        if(k == pai) continue;
        int h = dfs(k,node);
        if(h >= max1){
            max2 = max1;
            max1 = h;
        } else if ( h > max2){
            max2 = h;
        }
    }
    diametro = max(diametro, max1+max2);
    return max1+1;
}
 
 
int main() {
    cin >> n;
    adj.resize(n); 
    for(int i=0;i<n-1;i++){
        int a, b; cin >> a >> b; 
        a--; b --;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visitado(n);
    vector<int> dp(n,0);
    dfs(0, -1);
    cout << diametro;
}
