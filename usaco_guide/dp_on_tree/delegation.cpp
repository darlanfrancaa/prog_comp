#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int N = 1e5;
vector<int> adj[N];
int caminho_restante[N];

bool check(vector<int> &v, int remove, int k){
    int l = 0, r = v.size()-1; 
    while(l<r){
        if(l == remove) {l++; continue;}
        if(r == remove) {r--; continue;}
        if(v[l++] + v[r--] < k) return false; 
    }
    return true; 
}

bool dfs(int node, int p, int k){
    vector<int> v; // vai armazenar o tamanho dos caminhos para completar
    for(int u: adj[node]){
        if(u == p) continue;
        if(!dfs(u,node,k)) return false;
        v.push_back(caminho_restante[u] + 1);
    } 


    if(node == 0){
        // se for a raiz, então tem que ter uma quantidade par e tem que ser possível preencher sem remover nenhum valor
        if(v.size() % 2 == 1) v.push_back(0);
        sort(v.begin(), v.end());
        return check(v,-1,k);
    }
    if (v.size() % 2 == 0) {
		v.push_back(0);
	}
    sort(v.begin(), v.end());
    int l = -1; int r = v.size();
    // busca binária onde l vai armazenar o maior valor que pode ser enviado pra cima e, caso seja -1, é por que não foi possível fazer com k
    while(l < r - 1){
        int mid = l + (r-l)/2;
        if(check(v,mid,k)) l = mid;
        else r = mid;
    }


    if(l == -1) return false;
    caminho_restante[node] = v[l];
    return true;

}

signed main() {
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b; 
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    int l = 0; int r = n+1; 
    while(l < r - 1){
        int mid = l + (r-l)/2;
        fill(caminho_restante, caminho_restante + n, 0);
        if(dfs(0,0,mid)) l = mid; 
        else r = mid;
    }

    cout << l << "\n";
    return 0;
}