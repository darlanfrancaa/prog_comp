#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

vector<vector<int>> adj, comps, adj_cond;
vector<int> t_in, t_low;
int timer = 0;

void dfs(int v, vector<vector<int>> &adj, vector<vector<int>> &components){
    t_in[v] = t_low[v] = timer++;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}