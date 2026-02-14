#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 5e5+10;
// problem link: https://codeforces.com/problemset/problem/1418/G

int meu_rand() {
    int r1 = rand();
    int r2 = rand();
    int r3 = rand();
    int r4 = rand();

    return (1LL * r1 << 48) ^ (1LL * r2 << 32) ^ (1LL * r3 << 16 ) ^ r4;
}

int rand_val[MAXN];


signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    // agora eu quero lidar com a lógica de para cada i salvar o primeiro valor tal que todo mundo é <= 3, para isso, eu preciso da freq de cada cara e os 
    // últimos 3 lugares em que eles apareceram 
    srand(time(0));
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        rand_val[i] = meu_rand();
    }
    vector<int> valores(n); 
    vector<int> freq(n+1); 
    vector<queue<int>> pos(n+1);
    map<int, vector<int>> mapa;
    for(int i=0;i<n;i++) cin >> valores[i];
    int hash = 0;
    // o meu hash vai ser sum freq[i] * rand[i]
    mapa[0].push_back(-1);
    int last_valid = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        int val = rand_val[valores[i]]; // esse é o rand[i]
        hash -= val * freq[valores[i]];
        freq[valores[i]] = (freq[valores[i]] + 1) % 3; 
        hash += val * freq[valores[i]];
        // printf("o nosso valor aqui é %lld e sua frequencia era %lld e aumentou em 1\n", valores[i], freq[valores[i]]);
        pos[valores[i]].push(i);
        if(pos[valores[i]].size() > 3) {
            last_valid = max(last_valid, pos[valores[i]].front() + 1); 
            // essa é a primeira posição onde todo mundo tem valor <= 3
            pos[valores[i]].pop();
        }
        if (mapa.count(hash)) {
            vector<int> &indices = mapa[hash];
            auto it = lower_bound(indices.begin(), indices.end(), last_valid - 1);
            ans += (indices.end() - it);
        }
        mapa[hash].push_back(i);
        // agora em tese bastaria contar quantos caras nesse set são maiores do que a last_valid
        // cout << " a last_valid agora está valendo " << last_valid << endl;
        // auto it = lower_bound(mapa[hash].begin(), mapa[hash].end(), last_valid);
        // cout << "achei aqui qntd = " << qntd << " " << endl;
    }

    cout << ans << endl;

    return 0;
}