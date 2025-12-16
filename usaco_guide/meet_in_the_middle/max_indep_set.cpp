#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 41;
const int MAX_MASK = (1 << 20) + 5;
#define popcount __builtin_popcountll

int n, m;
int adj[MAXN];

struct No{
    bool is_ind;
    int greater_ind_inside;
};

No dp[MAX_MASK];

bool is_idep(int mask){
    for(int i=0; i< popcount(mask);i++){
        if((mask & (1<<i)) && (mask & adj[i])) return false;
    }
    return true;
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m; 
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b; 
        adj[a] |= (1LL << b);
        adj[b] |= (1LL << a);
    }

    // então eu quero salvar para cada vértice uma informação se ele é um conjunto independente e qual o maior subconjunto independente dentro dele, para cada mask
    int n1 = n /2; 
    int n2 = n - n1;

    for(int mask = 0; mask < (1 << n1); mask++){
        bool ind = true;
        for(int j = 0; j<n1;j++){
            if((mask & (1LL << j))  && (mask & adj[j])) { 
                dp[mask].is_ind = false;
                ind = false;
                break;
            }
        }
        if(ind) dp[mask].is_ind = true;
    }

    for(int mask = 0; mask < (1 << n1); mask++){
        if(dp[mask].is_ind){
            dp[mask].greater_ind_inside = mask;
            continue;
        }
        dp[mask].greater_ind_inside = 0;
        for(int i = 0; i < n1; i++){
            // agora eu gostaria de saber o valor de cada submask dessa mask
            if(mask & (1LL<<i)){
                int new_mask = mask ^ (1LL << i);
                int best_new_mask = dp[new_mask].greater_ind_inside;
                if(popcount(dp[mask].greater_ind_inside) < popcount(best_new_mask)){
                    dp[mask].greater_ind_inside = best_new_mask;
                }   
            }
        }
    }

    int best_mask = 0; 
    int max_size = 0;

    for(int mask2 = 0; mask2 < (1LL << n2); mask2++){
        bool ok = true;
        int real_mask = (mask2 << n1);
        for(int i=0;i<n2;i++){
            if(mask2 & (1LL << i)){
                int u = n1 + i; 
                if(adj[u] & real_mask){
                    ok = false; 
                    break;
                }
            }
        }

        if(!ok) continue; // então aqui só passa aquelas que são um conj indep
        int forb_parta = 0; 
        for(int i=0;i<n2;i++){
            if(mask2 & (1LL << i)){
                int u = n1 + i;
                forb_parta |= (adj[u] & ((1LL << n1) - 1));
            }
        }

        int mask_perm = ((1LL<<n1) - 1) ^ forb_parta;
        int best_mask_parta = dp[mask_perm].greater_ind_inside;

        int final = real_mask | best_mask_parta;
        int curr_size = popcount(final);

        if(curr_size > max_size){
            max_size = curr_size;
            best_mask = final;
        }
    }

    cout << max_size << "\n";

    for(int i=0;i<n;i++){
        if(best_mask & (1LL<<i)){
            cout << i << " ";
        }
    }

    cout << "\n";


    return 0;
}