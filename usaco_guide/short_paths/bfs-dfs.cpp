#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> bfs(n),dfs(n);
    if (n==1){
        cout << 0 << endl;
        return 0; 
    }
    for(auto &num:bfs) cin >> num; 
    for(auto &num:dfs) cin >> num; 
    if(bfs[1] != dfs[1]){
        cout << -1 << endl; 
        return 0; 
    }
    cout << 2*n - 3 << endl; 
    for(int i=1;i<n;i++){
        cout << 1 << " " << bfs[i] << endl;
    }
    for(int i=1;i<n-1;i++){
        cout << dfs[i] << " " << dfs[i+1] << endl;
    }
    return 0;
}