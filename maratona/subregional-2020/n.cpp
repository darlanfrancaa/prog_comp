#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX_P = 32000000;

bitset<MAX_P+1> is_prime;
vector<int> primes; 

void build_crivo(){
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for(int i=2; i*i <= MAX_P ; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=MAX_P;j+=i){
                is_prime[j] = 0;
            }
        }
    }

    for(int i=2;i<= MAX_P;i++){
        if(is_prime[i]) primes.push_back(i);
    }
}

struct Edge { 
    int v; 
    int peso;
};

const int MAX_N = 1005;
int C[MAX_N], rep[MAX_N], ans[MAX_N];
vector<Edge> adj[MAX_N];

signed main() {
    int m,n,k; cin >> m >> n >> k; 
    for(int i=1;i<=n;i++){
        cin >> C[i];
    }

    for(int i=0;i<k;i++){
        int u,v,w; cin >> u >> v >> w; 
        rep[u] = v;
        adj[u].push_back({v,w});
    }
    build_crivo();
    int curr_m = 1;
    for(int p:primes) {
        if(curr_m > m) break;
        int repr = rep[curr_m];
        if(C[repr] % p == 0){
            ans[curr_m] = p;
            for(Edge e: adj[curr_m]){
                for(int d=0;d<e.peso;d++){
                    C[e.v] /= p;
                }
            }
            curr_m++;
        }
    }

    for(int i=curr_m; i<= m;i++){
        ans[i] = C[rep[i]];
    }

    for(int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }


    return 0;
}