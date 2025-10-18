#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int LOG = 21; 
const int MAXN = 2e5 + 10;

int n,m;

vector<vector<int>> adj;
vector<int> colors, first, last, et, depth;
map <int,int> contador_cores; 
vector<vector<int>> dp;

int timer = 0;

void dfs(int p, int v, int d){
    if(first[v] == 0) first[v] = timer;
    last[v] = timer;
    depth[v] = d;
    et[timer++] = v;
    dp[v][0] = p; 

    for(auto &node : adj[v]){
        if( node != p){
            dfs(v,node,d+1);
            et[timer] = v;
            last[v] = timer++;
        }
    }
}

void fill_dp(){
    for(int j=1;j<LOG;j++){
        for(int i=0;i<n;i++){
            if(dp[i][j-1] != -1) dp[i][j] = dp[dp[i][j-1]][j-1];
            else dp[i][j] = -1; 
        }
    }
}

int up(int v, int k){
    for(int j=LOG-1;j>=0;j--){
        if(k & (1 << j)) {
            if(v == -1) return -1;
            v = dp[v][j];
        }
    }
    return v;
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    int diff = depth[u] - depth[v]; 
    u = up(u, diff); 
    if(u == v) return u; 
    for(int j=LOG-1;j>=0;j--){
        if(dp[u][j] != -1 && dp[u][j] != dp[v][j]){
            u = dp[u][j]; 
            v = dp[v][j];
        }
    }
    return dp[v][0];
}

struct Big_Query{
    int u, v, lca, cor;
};

vector<Big_Query> big_queries;

struct Small_Query{
    int cor, idx_query, posicao;
};

vector<Small_Query> small_queries[MAXN];
int ans[MAXN][3]; // vai salvar a respostar das small_queries caso o vertice esteja na primeira(0), segunda ou terceira posicao da query;

void solve_dfs(int p, int u){
    contador_cores[colors[u]]++;

    for(auto &q: small_queries[u]){
        auto [cor, i, posicao] = q;
        int num_cor = contador_cores[cor]; 
        ans[i][posicao] = num_cor;
    }

    for(auto &node: adj[u]){
        if (node != p){
            solve_dfs(u, node);
        }
    }

    contador_cores[colors[u]]--;
}




signed main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; 
    colors.resize(n); first.resize(n,0); last.resize(n,0); et.resize(2*n -1); depth.resize(n);
    dp.resize(n, vector<int>(LOG,-1));
    adj.resize(n);

    for(int i=0;i<n;i++){
        cin >> colors[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b; 
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    dfs(-1,0,0);
    fill_dp();
    big_queries.resize(m);


    for(int i=0;i<m;i++){
        int u,v, cor; cin >> u >> v >> cor; 
        u--, v--; 
        int l = lca(u,v);
        big_queries[i] = {u,v,l,cor};
        // queremos saber para a query i a quantidade de cores cor da raiz até cada um dos vertices u,v,l; 
        small_queries[u].push_back({cor,i,0});
        small_queries[v].push_back({cor,i,1});
        small_queries[l].push_back({cor,i,2});

    }


    solve_dfs(-1,0);

    for(int i=0;i<m;i++){
        int lca = big_queries[i].lca;
        int cor_atual = big_queries[i].cor;

        int total = ans[i][0] + ans[i][1] - 2 * ans[i][2];

        if(colors[lca] == cor_atual) total++;
        if(total > 0) cout << "1"; 
        else cout << "0";
        
    }

    return 0;
}