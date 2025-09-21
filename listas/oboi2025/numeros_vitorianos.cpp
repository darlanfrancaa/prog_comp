#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    if(n == 1){
        cout << 1 << "\n"; 
        return 0;
    }
    queue<int> q; 
    q.push(1); 
    vector<int> parent(n, -1);
    vector<int> number(n,-1);
    vector<int> visitado(n, 0);
    parent[1] = -2;
    number[1] = 1;
    visitado[1] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop(); 
        if(u == 0) break;
        int v1 = (u * 10) % n;
        if(!visitado[v1]){
            visitado[v1] = 1;
            parent[v1] = u; 
            number[v1] = 0;
            q.push(v1);
        }
        int v2 = ((u * 10) + 1) % n;
        if(!visitado[v2]){
            visitado[v2] = 1;
            parent[v2] = u; 
            number[v2] = 1;
            q.push(v2);
        }
    }
    int curr = 0; 
    vector<int> ans;
    while(curr != -2){
        int past = parent[curr];
        ans.push_back(number[curr]);
        curr = past;
    }
    reverse(ans.begin(), ans.end());
    for(auto v: ans){ 
        cout << v;
    }
    
    return 0;
}