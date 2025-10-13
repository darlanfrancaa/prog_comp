#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

const int DIGITOS = 4;
const int ALL_BITS = 1 << DIGITOS;
const int MAXN = 30;

void solve(int n, int k){
    /* n representa o número de dígitos do número e k o número que queremos analisar a divisibilidade */
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(k, vector<long long>(ALL_BITS, 0)));
    dp[0][0][0] = 1;
    for(int idx = 0; idx < n; idx++){
        for(int resto = 0; resto < k; resto++){
            for(int mask = 0; mask < ALL_BITS; mask++){
                // em cada iteração eu vou adicionar o valor do estado atual no próximo
                // se esse valor já for 0 eu pulo
                if(dp[idx][resto][mask] == 0) continue;
                for(int dig = 1; dig <= DIGITOS; dig++){
                    int novo_resto =  ( 10 * resto + dig ) % k;
                    int new_mask = mask | (1 << (dig - 1));
                    dp[idx+1][novo_resto][new_mask] += dp[idx][resto][mask];
                }
            }
        }
    }

    int ans = dp[n][0][ALL_BITS - 1];
    printf("sem otimizar a memória: %lld\n", ans);
}

void solve_with_less_memory(int n, int k){
    /* n representa o número de dígitos do número e k o número que queremos analisar a divisibilidade */
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(k, vector<int>(ALL_BITS, 0)));
    dp[0][0][0] = 1;
    for(int id = 0; id < n; id++){
        // ajeitando otimização de espaço
        int idx_atual = id % 2;
        int next_idx = (id+1) % 2;
        // setando o próximo estado como 0
        for (auto& row : dp[next_idx]) {
            std::fill(row.begin(), row.end(), 0);
        }

        for(int resto = 0; resto < k; resto++){
            for(int mask = 0; mask < ALL_BITS; mask++){
                // em cada iteração eu vou adicionar o valor do estado atual no próximo
                // se esse valor já for 0 eu pulo
                if(dp[idx_atual][resto][mask] == 0) continue;
                for(int dig = 1; dig <= DIGITOS; dig++){
                    int novo_resto =  ( 10 * resto + dig ) % k;
                    int new_mask = mask | (1 << (dig - 1));
                    dp[next_idx][novo_resto][new_mask] += dp[idx_atual][resto][mask];
                }
            }
        }
    }
    int idx_final = n % 2;
    int ans = dp[idx_final][0][ALL_BITS - 1];
    printf("otimizando a memória: %lld\n", ans);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, p; cin >> n >> p; 
    clock_t inicio = clock(), fim; 

    solve(n,p);
    fim = clock();
    double tempo = double(fim - inicio)/ CLOCKS_PER_SEC;
    printf("o tempo para essa parte foi de %f\n", tempo);

    inicio = clock();
    solve_with_less_memory(n , p);
    fim = clock();
    tempo = double(fim - inicio)/ CLOCKS_PER_SEC;
    printf("o tempo para essa parte foi de %f\n", tempo);

    
    return 0;
}