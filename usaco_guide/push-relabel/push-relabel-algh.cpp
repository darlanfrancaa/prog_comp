#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

const int inf = 1e9;

int n; 
vector<vector<int>> capacity, flow; 
vector<int> height, excess, seen;
queue<int> excess_vertex;

void push(int u, int v){
    int d = min(excess[u], capacity[u][v] - flow[u][v]); // eu pego o mínimo entre o que tá sobrando de u e o que a aresta suporta
    flow[u][v] += d; 
    flow[v][u] -= d; 
    excess[u] -= d; 
    excess[v] += d; 
    if(d && excess[v] == d){
        excess_vertex.push(v);
    }
}

void relabel(int u){
    int d = inf;
    for(int i=0;i<n;i++){
        if(capacity[u][i] - flow[u][i] > 0){
            d = min (d, height[i]);
        }
    }

    if(d < inf) height[u] = d + 1; 
}

void discharge(int u){
    while(excess[u] > 0){
        if(seen[u] < n){
            int v = seen[u];
            if(capacity[u][v] - flow[u][v] > 0 && height[u] > height[v])
                push(u,v);
            else 
                seen[u]++;

        } else { 
            relabel(u);
            seen[u] = 0;
        }
    }
}

int max_flow(int s, int t){
    height.assign(n,0);
    height[s] = n; 
    flow.assign(n, vector<int> (n,0));
    excess.assign(n,0);
    excess[s] = inf;
    for(int i = 0; i < n; i++){
        if(i!= s){
            push(s, i);
        }
    }
    seen.assign(n,0);
    while(!excess_vertex.empty()){
        int u = excess_vertex.front(); excess_vertex.pop();
        if(u != s && u != t) discharge(u);
    }

    int max_flow = 0; 
    for(int i=0;i<n;i++){
        max_flow += flow[i][t];
    }

    return max_flow;    
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}