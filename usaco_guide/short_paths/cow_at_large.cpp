#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    //freopen("atlarge.in", "r", stdin);
    //freopen("atlarge.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k; 
    vector<vector<int>> adj(n,vector<int>());
    for(int i =0;i<n;i++){
        int a, b; cin >> a >> b; 
        --a; --b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist1(n,INT_MAX), dist2(n, INT_MAX);
    dist2[k] = 0; 
    queue<int> q;
    q.push(k);
    // armazenar a distância da vaca k para cada uma dos vértices
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v: adj[u]){
            if(dist2[u] + 1 < dist2[v]){
                dist2[v] = dist2[u] + 1; 
                q.push(u);
            }
        }
    }
    // agora quero procurar a menor distância de cada vértice para algumas de suas folhas
    for(int i=0;i<n;i++){
        if(adj[i].size() == 1){ 
            q.push(i); 
            dist1[i] = 0;
        }
    }

    while(!q.empty()){
        int u = q.front(); q.pop(); 
        for(auto v: adj[u]){
            if(dist1[u] + 1 < dist1[v]){
                dist1[v] = dist1[u] +1 ;
                q.push(v);
            }
        }
    }

    int ans = 0; 
    q.push(k);
    vector<int> visitado(n);
    while(!q.empty()){
        int v = q.front(); q.pop(); 
        if(dist1[v] <= dist2[v]){
            ans++;
            continue; 
        }
        if(visitado[v]) continue; 
        visitado[v] = 1; 
        for(auto u: adj[v]){
            q.push(u);
        }
    }
    cout << ans << endl;
    return 0;
}
