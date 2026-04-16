#include <bits/stdc++.h>
using namespace std;

// #define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
#pragma GCC optimize("Ofast")

// problem link: 
const int N = 1e5+10;
const int B = 320; 
const int inf = 1e9;
vector<int> adj[N];
vector<pii> dp[N]; // vou guardar o par {vértice, distância}
bool livre[N];
int dp1[N];

bool ja_tem; 
bool visitado[N];

vector<pii> merge(const vector<pii> &a, const vector<pii> &b) {
    vector<pii> resposta;
    int ptr_a = 0;
    int ptr_b = 0; 
    while (resposta.size() < B && (ptr_a < a.size() || ptr_b < b.size())) {  
        pii escolhido;
        if (ptr_b >= b.size() || (ptr_a < a.size() && a[ptr_a].second >= b[ptr_b].second + 1)) {
            escolhido = a[ptr_a];
            ptr_a++;
        } else {
            escolhido = {b[ptr_b].first, b[ptr_b].second + 1};
            ptr_b++;
        }
        bool ja_tem = false;
        if (visitado[escolhido.first]) {
            ja_tem = true;
        }
        if (!ja_tem) {
            resposta.push_back(escolhido);
            visitado[escolhido.first] = true;
        }
    }
    for (auto p : resposta) {
        visitado[p.first] = false;
    }
    
    return resposta;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,q; cin >> n >> m >> q; 
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b; // é sempre garantido que a < b
        adj[b].push_back(a); // eu pego o grafo invertido para fazer a bfs e calcular o cara mais distante para cada vértice
    }
    for(int i=1;i<=n;i++){
        dp[i].push_back({i,0}); // vértice inalcançável e com distância mínima
    }
    // então para cada vértice eu vou salvar os B caras mais distantes. 
    for(int i=1;i<=n;i++){
        for(auto node: adj[i]){
            dp[i] = merge(dp[i], dp[node]);
        }
    }
    fill(livre, livre + N, true);
    for(int i=0;i<q;i++){
        int begin, qntd; cin >> begin >> qntd;
        vector<int> bloqueados(qntd);
        for(int i=0;i<qntd;i++){
            cin >> bloqueados[i];
            livre[bloqueados[i]] = false;
        }
        if(qntd >= B){
            for(int i =0;i<=begin;i++) dp1[i] = -1;

            dp1[begin] = 0;
            int maximo = -1; 
            
            for(int i = begin; i>=1; i--){
                if(dp1[i] == -1) continue;
                if(!livre[i]) continue;
                maximo = max(maximo, dp1[i]);

                for(auto node: adj[i]){
                    if(livre[node]){
                        dp1[node] = max(dp1[node], dp1[i] +1);
                    }
                }
            }
            cout << maximo << "\n";
        } else {
            int ans = -1; 
            for(auto [node,dist]: dp[begin]){
                if(livre[node]){
                    ans = dist;
                    break;
                }
            }
            cout << ans << "\n";
        }
        for(int node : bloqueados){
            livre[node] = true;
        }
    }
    return 0;
}