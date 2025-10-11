#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// eu preciso encontrar o menor filme tal que fi > c 

int upper_bound_me(const vector<int> v, int valor){
    // cout << "\nestou tentando achar a upper para o valor " << valor << " do vetor "; 
    // for(auto a: v) cout << a << " ";
    int left = 0; int right = v.size()-1; 
    if(v[left] > valor) {
        // cout << endl << "e a minha resposta foi " << left << "\n";
        return left;
    }
    if(v[right] <= valor){ 
        // cout << endl << "e a minha resposta foi " << right+1 << "\n";
        return right+1;
    }
    while(right - left > 1){
        int mid = (left + right)/2;
        if(v[mid] > valor) right = mid;
        else left = mid;
    }
    // cout << endl << "e a minha resposta foi " << right << "\n";
    return right;

}

signed main() {
    freopen("movie.in", "r", stdin);
    freopen("movie.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, l; cin >> n >> l; 
    int M = (1 << n);
    vector<int> duracao(n);
    vector<vector<int>> filmes(n);
    vector<int> max_mask(M,-1);
    for(int i=0;i<n;i++){
        cin >> duracao[i];
        int c; cin >> c;
        for(int j=0;j<c;j++){
            int f; cin >> f; 
            filmes[i].push_back(f);
        }
    }
    /* a minha ideia é fazer uma dp[mask][filme] que vai armazenar o maior L que é possível chegar com essa mask e parando 
    nesse filme por último */

    vector<vector<int>> dp(M, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        if (binary_search(filmes[i].begin(), filmes[i].end(), 0)) {
            dp[1 << i][i] = duracao[i];
            max_mask[1 << i] = max(max_mask[1 << i], duracao[i]);
        }
    }

    for(int mask = 1; mask < M; mask++){
        if (max_mask[mask] == -1) continue;    

        for(int i = 0; i < n;i++){
            if((mask & (1 << i))) continue; 
            int prev_time = max_mask[mask];
            int idx = upper_bound_me(filmes[i], prev_time) - 1;
            if(idx >= 0){
                int comeco_filme = filmes[i][idx];
                int fim_filme = comeco_filme + duracao[i];
                int next_mask = mask | (1 << i);
                if(fim_filme > dp[next_mask][i]){
                    dp[next_mask][i] = fim_filme;
                    max_mask[next_mask] = max(max_mask[next_mask], fim_filme);
                }
            }
                
        }
        
    }
    int ans = LLONG_MAX; 
    for(int mask = 1; mask < M; mask++){
        if(max_mask[mask] >= l) ans = min(ans, (int)__builtin_popcount(mask));
    }
    if(ans == LLONG_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}