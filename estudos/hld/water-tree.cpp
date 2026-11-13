#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 5e5+10;

// problem link: https://codeforces.com/problemset/problem/343/D

int lz[4*MAXN]; // vai ser -1 se não tiver o que analisar, 1 se for todo mundo 1 no intervalo e 0 se for pra ser todo mundo 0

void push(int p, int l, int r){
    if(lz[p] == -1) return; // não tem atualizações nesse nó a serem feitas
    lz[2*p] = lz[p];
    lz[2*p+1] = lz[p];
    lz[p] = -1;
}

void update_seg(int p, int l, int r, int ql, int qr, int val){
    if(l > qr || r < ql) return;
    if(ql <= l && r <= qr) {
        lz[p] = val;
        return;
    }
    push(p,l,r);
    int m = (l+r)/2;
    update_seg(2*p, l, m, ql, qr, val);
    update_seg(2*p+1,m+1,r,ql,qr,val);
}

int query_pos(int p, int l, int r, int pos){
    if(lz[p] != -1) {
        // já que tem que atualizar todos seus filhos para o valor de lazy, é só retornar ele
        return lz[p];
    } 
    // não vai precisar dar push por que lazy é -1
    int m = (l+r)/2;
    if(pos <= m) return query_pos(2*p, l, m, pos);
    else return query_pos(2*p+1,m+1,r,pos);
}

vector<int> adj[MAXN];
int sz[MAXN], par[MAXN], dep[MAXN], head[MAXN], heavy[MAXN], pos[MAXN];
int n, curr = 0;
int calcsize(int u, int p){
    sz[u] = 1;
    int best = 0;
    for(auto v: adj[u]) if(v != p){
        par[v] = u; dep[v] = dep[u] + 1; 
        sz[u] += calcsize(v, u);
        if(sz[v] >= best){
            best = sz[v];
            heavy[u] = v;
        }
    }
    return sz[u];
}

void decompose(int u, int h){
    head[u] = h; pos[u] = curr++;
    if(heavy[u] != -1) decompose(heavy[u],h);
    for(auto v: adj[u]) {
        if(v != par[u] && v != heavy[u]) decompose(v,v);
    }
}

void build(int start){
    calcsize(start,-1);
    decompose(start,start);
}

void update_subtree(int v){
    int p = pos[v];
    update_seg(1,0,n-1,p, p+sz[v]-1, 1);
}

// colocar o caminho de v até a raiz (0) com 0
// faz logn updates em lazy
void update_path(int v){
    while(head[v] != 0){
        int p = pos[v], p_head = pos[head[v]];
        update_seg(1,0,n-1,p_head, p, 0);
        v = par[head[v]];
    }
    update_seg(1,0,n-1, 0, pos[v], 0);
}

void initialize(){
    fill(heavy, heavy+n, -1);
    fill(lz, lz+4*MAXN, -1);
    dep[0] = 0;
    par[0] = 0;
    lz[1] = 0;
    build(0);
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n; 
    for(int i=0;i<n-1;i++){
        int a, b; cin >> a >> b; 
        a--;b--; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int q; cin >> q; 
    initialize();
    while(q--){
        int op, v; cin >> op >> v; v--; 
        if(op == 1){
            update_subtree(v);
        } else if (op == 2){
            update_path(v);
        } else {
            cout << query_pos(1,0,n-1,pos[v]) << "\n";
        }
    }
    return 0;
}