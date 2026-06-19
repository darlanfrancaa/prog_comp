#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int n;

vector<vector<int>> cap, flow; 
vector<int> height, excess, seen;
queue<int> exc_vert;

void push(int u, int v){
    int d = min(excess[u], cap[u][v] - flow[u][v]);
    flow[u][v] += d; 
    flow[v][u] -= d; 
    excess[u] -= d; 
    excess[v] += d;
    if(d > 0 && excess[v] == d) exc_vert.push(v); 
}

void relabel(int u){
    int minimo = LLONG_MAX;
    for(int v = 0; v < n; v++){
        if(cap[u][v] - flow[u][v] > 0) minimo = min(minimo, height[v]);
    }
    if(minimo < LLONG_MAX) height[u] = minimo + 1; 
}

void discharge(int u){
    while(excess[u] > 0){
        if(seen[u] < n){
            int v = seen[v];
            if(cap[u][v] - flow[u][v] > 0 && height[u] > height[v]) push(u,v);
            else seen[u]++;
        } else {
            relabel(u);
            seen[u] = 0;
        }
    }
}

int max_flow(int s, int t){
    height.assign(n,0);
    height[s] = n; 
    excess.assign(n,0);
    excess[s] = LLONG_MAX;
    flow.assign(n,vector<int>(n,0));
    seen.assign(n,0);
    for(int i=0;i<n;i++){
        if(i != s) push(s,i);
    }

    while(!exc_vert.empty()){
        int u = exc_vert.front(); exc_vert.pop();
        if(u != s && u != t) discharge(u);
    }
    int max_flow = 0;
    for(int i=0;i<n;i++){
        max_flow += flow[s][i];
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}