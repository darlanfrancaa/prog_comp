#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

vector<int> cor;
vector<vector<int>> adj;
vector<int> final_order;
bool has_cycle = false;
void dfs(int v, vector<int> &order){
    cor[v] = 1; 
    for(auto u: adj[v]){
        if(cor[u] == 0) dfs(u, order);
        else if(cor[u] == 1) has_cycle = true;
    }
    cor[v] = 2;
    order.push_back(v);
}

void topological_order(){
    int n = adj.size();
    cor.assign(n,0);
    final_order.clear();
    for(int i=0;i<n;i++){
        if(cor[i] == 0) dfs(i, final_order);
    }
    reverse(final_order.begin(), final_order.end());
    if(has_cycle){
        cout << "Impossivel";
        final_order.clear();
    }
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}