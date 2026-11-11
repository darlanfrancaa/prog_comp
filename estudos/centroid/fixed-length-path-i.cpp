#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 2e5+10;

// problem link: 

int n, k;
vector<int> adj[MAXN];
bool removed[MAXN];
int sz[MAXN];
long long cnt[MAXN];
vector<int> dist_atuais;
long long ans = 0;

int calcSize(int u, int p){
    // só pra calcular o valor do size de cada subárvore
    sz[u] = 1; 
    for(auto v: adj[u]){
        if(v != p && !removed[v]){
            sz[u] += calcSize(v,u);
        }
    }
    return sz[u];
}

int findCentroid(int u, int p, int tot){
    for(int v:adj[u]){
        if(v != p && !removed[v] && sz[v] * 2 > tot) return findCentroid(v,u,tot); // caso tenha encontrado alguém ja retorna
    }
    return u; // caso contrário, ele é um centroid válido
}

// salva em dist_atuais os valores das distancias na subárvore de u assumindo que ele começa vazio
void collect(int u, int p, int d){
    if(d>k) return; // otimização para não precicar fazer sempre o(n) operações
    dist_atuais.push_back(d); 
    for(int v:adj[u]){
        if(v != p && !removed[v]) collect(v,u,d+1);
    }
}

void solve(int start){
    int c = findCentroid(start, -1, calcSize(start,-1));
    cnt[0] = 1; 
    int max_dist = 0;
    for(int v:adj[c]){
        if(removed[v]) continue;
        dist_atuais.clear();
        collect(v,c,1);
        for(int d:dist_atuais) ans += cnt[k-d];
        for(int d:dist_atuais) {
            cnt[d]++; 
            max_dist = max(max_dist, d); 
        }
    }
    for(int d = 0; d <= max_dist;d++) cnt[d] = 0; 
    // precisamos reiniciar o vetor de contador de distâncias para calcular o pŕoximo centroid, mas só precisamos fazer 
    // isso até a distãncia máxima anterior, visto que não vão existir distâncias maiores que essas dentro de cada subárvore]
    removed[c] = true; 
    for(int v: adj[c]){
        if(!removed[v]) solve(v);
    }
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k; 
    for(int i=0;i<n-1;i++){
        int a, b; cin >> a >> b; 
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(0);
    cout << ans << "\n";
    return 0;
}