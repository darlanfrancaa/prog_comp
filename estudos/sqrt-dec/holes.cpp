#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int N  = 1e5+10;
const int B  = 320;
const int inf = 1e7;
// problem link: https://codeforces.com/problemset/problem/13/E

// a ideia é tentar salvar para cada cara qual a próxima posição que ele sai do bloco dele e em quantos passos

struct Node{
    int prox_val; 
    int passos; 
    int last_val; // vai salvar a última posição antes de sair do bloco
};

int v[N]; 
Node proximo_bloco[N];

pii query(int idx, int n){
    // printf("entrei na query com idx = %lld\n", idx);
    int curr = idx; 
    int total_passos = 0;
    while(proximo_bloco[curr].prox_val < n){
        // printf("estou pulando de curr = %lld para curr = %lld e até agora eu dei %lld passos.\n", curr, proximo_bloco[curr].first ,proximo_bloco[curr].second);
        total_passos += proximo_bloco[curr].passos;
        curr = proximo_bloco[curr].prox_val;
    }
    total_passos += proximo_bloco[curr].passos;
    return {proximo_bloco[curr].last_val, total_passos};
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m; 
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=n-1;i >= 0;i--){
        if(v[i] + i >= B*(i/B + 1) || v[i] + i >= n){
            proximo_bloco[i] = {v[i] + i,1, i};
        } else { // então eu dei o pulo e caiu no mesmo bloco só que pra frente
            auto [pos, val, last] = proximo_bloco[v[i] + i];
            proximo_bloco[i] = {pos, val+1, last};
        }
    }
    for(int i=0;i<n;i++){
        // printf("analisando i = %lld, temos o par {%lld, %lld ,  %lld}\n", i,proximo_bloco[i].prox_val, proximo_bloco[i].passos, proximo_bloco[i].last_val);
    }
    for(int i=0;i<m;i++){
        // printf("passei aqui em i = %lld\n", i);
        int op; cin >> op; 
        if(op == 1) {
            int idx; cin >> idx; 
            idx--;
            auto [f,s] = query(idx, n); 
            cout << f + 1 << " " << s << "\n";
        } else {
            int pos, val ; cin >> pos >> val;
            pos--;
            v[pos] = val;
            int bloco = pos/B;
            for(int i=min((bloco+1)*B - 1,n-1); i>= bloco*B; i--){
                if(v[i] + i >= B*(i/B + 1) || v[i] + i >= n){
                    proximo_bloco[i] = {v[i] + i,1, i};
                } else { 
                    auto [pos, val, last] = proximo_bloco[v[i] + i];
                    proximo_bloco[i] = {pos, val+1, last};
                }           
            }
            for(int i=0;i<n;i++){
                // printf("analisando i = %lld, temos o par {%lld, %lld ,  %lld}\n", i,proximo_bloco[i].prox_val, proximo_bloco[i].passos, proximo_bloco[i].last_val);
            }
        }
    }
    return 0;
}
