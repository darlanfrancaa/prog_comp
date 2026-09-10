#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: 

const int MAXN =  2e5;

vector<int> adj[MAXN+1];

set<int> color[MAXN+1];
int distinct_num[MAXN+1];

void process_color(int curr, int parent){
    for(int n: adj[curr]){
        if(n!=parent){
            process_color(n, curr);
            if(color[curr].size() < color[n].size()){
                swap(color[curr], color[n]);
            }
            for(int val: color[n]) color[curr].insert(val);
        }
    }
    distinct_num[curr] = color[curr].size();
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n; 
    for(int i=1;i<=n;i++){
        int a; cin >> a; 
        color[i].insert(a);
    }
    for(int i=1;i<n;i++){
        int a, b; cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    process_color(1,0);
    for(int i=1;i<=n;i++) {
        cout << distinct_num[i] << " ";
    }
    return 0;
}