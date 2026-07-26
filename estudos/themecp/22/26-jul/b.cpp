#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: 

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    int maximo = LLONG_MIN;
    map<int,int> freq;
    for(int i=0;i<n;i++){
        int a; cin >> a; 
        v[i] = a;
        freq[a]++;
        maximo = max(maximo, a);
    }

    auto evaluate = [&](const vector<int> &cand) -> int {
        vector<bool> visited(n+2, false);
        int curr_mex = 0, curr_max = 0, soma = 0; 
        for(int x: cand){
            curr_max = max(curr_max, x);
            if(x <= n+1) visited[x]= true;
            while(visited[curr_mex]) curr_mex++;
            soma += (curr_mex + curr_max);
        }
        return soma;
    };

    // primeiro caso vai ser tentar fazer maximo ir pro comeco e ir colocando os indices de cada valor
    vector<int> resp1;
    map<int,int> f1 = freq;
    resp1.push_back(maximo);
    f1[maximo]--;

    for(auto &[val, qtd]: f1){
        if(qtd > 0){
            resp1.push_back(val);
            qtd--;
        }
    }

    for(auto &[val,qtd]: f1){
        while(qtd > 0){
            resp1.push_back(val);
            qtd--;
        }
    }

    // segundo caso é só tentar colocar 0,1,2.., mex, max,max,...
    // conjecturo que o máximo vai tá entre essas duas respostas

    vector<int> resp2;
    map<int,int> f2 = freq; 

    for(auto &[val, qtd]: f2){
        if(qtd > 0){
            resp2.push_back(val);
            qtd--;
        }
    }

    for(auto &[val, qtd]: f2){
        while(qtd > 0){
            resp2.push_back(val);
            qtd--;
        }
    }

    int ans = max(evaluate(resp1), evaluate(resp2));
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}