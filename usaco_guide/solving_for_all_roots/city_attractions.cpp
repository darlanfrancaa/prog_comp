#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 3e5+3;
int n,k;

vector<int> adj[MAXN];
int a[MAXN]; 
pii dp1[MAXN]; // em dp1 vai armazenar para cara subarvore o par {vertice, valor} onde o vértice é o tal que tem a maior energia = valor
pii ans[MAXN];

pii maximo(pii a, pii b){
    if(a.second < b.second) return b; 
    else return a;
}

void dfs1(int node = 1, int p = 0){
    dp1[node] = {node,a[node]};
    for(int v: adj[node]){
        if(v != p){
            dfs1(v, node); // preciso do filho, então eu chamo pra calcular logo.
            pii par_v = {dp1[v].first, dp1[v].second - 1}; // para uma subárvore de v, a distância do maior para o pai de v aumenta 1 e nossa energia diminui.   
            dp1[node] = maximo(dp1[node], par_v);
        }
    } 
}

void dfs2(int node = 1, int p = 0, pii best_p = {-1LL, LLONG_MIN}){
    ans[node] = maximo(dp1[node], best_p);
    vector<pii> filhos_dp; 
    for(int v: adj[node]){
        if(v != p){
            filhos_dp.push_back({v, dp1[v].second - 1});
        }
    }
    if(filhos_dp.empty()) return;
    int num = filhos_dp.size();
    vector<pii> preffix(num);
    vector<pii> suffix(num);

    preffix[0] = filhos_dp[0];
    for(int i=1;i<num;i++){
        preffix[i] = maximo(preffix[i-1], filhos_dp[i]);
    }
    suffix[num-1] = filhos_dp[num-1];
    for(int i = num - 2; i >= 0; i--){
        suffix[i] = maximo(suffix[i+1], filhos_dp[i]);
    }

    for(int i = 0;i< num;i++){
        int v = filhos_dp[i].first;
        pii best_node = {-1LL, LLONG_MIN};
        if(i > 0){
            best_node = maximo(best_node, preffix[i-1]);
        }
        if(i < num - 1){
            best_node = maximo(best_node, suffix[i+1]);
        }

        best_node = maximo(best_node, {node, a[node]});
        best_node = maximo(best_node, best_p);
        best_node = {best_node.first, best_node.second - 1};

        dfs2(v, node, best_node);
    }
}

int solve(int k){
    map<int,int> mapa; // vou salvar para cada vértice v, o primeiro tempo em que chegamos ao vértice v.
    vector<int> caminho;

    int contador = 0; 
    int curr = 1; 
    while(contador < k){
        if(mapa.find(curr) != mapa.end()){
            int primeiro = mapa[curr];
            int tamanho = contador - primeiro;

            int rem = k - contador;
            int rem_ciclo = rem % tamanho;
            return caminho[primeiro + rem_ciclo];
        }
        mapa[curr] = contador;
        caminho.push_back(curr);
        curr = ans[curr].first;
        contador++;
    }

    return curr;
}


signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1();
    dfs2();
    cout << solve(k) << "\n";

    
    return 0;
}