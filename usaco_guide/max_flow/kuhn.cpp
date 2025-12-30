#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

vector<vector<int>> adj;
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

// invariantes: sempre que um vértice está saturado ele continua saturado tanto na esquerda como na direita

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int result = 0; 
    int n,m;
    match.assign(m, -1);
    for(int i=0;i<n;i++){
        used.assign(n,false);
        if(try_kuhn(i)) result++;
    }
    cout << result << "\n";
    return 0;
}