#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

/*link do problema: https://codeforces.com/contest/1225/problem/D */

typedef pair<int,int> pii;

vector<pii> fatoracao(int n, int k){
    vector<pii> ans;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int potencia = 0;
            while(n % i==0){
                potencia++;
                n /= i;
            }
            if(potencia%k==0) continue;
            ans.push_back({i,potencia % k});
        }
    }
    if(n>1){
        ans.push_back({n,1});
    }
    return ans;
}

vector<pii> complementar(const vector<pii> &pares, int k){
    vector<pii> ans;
    for(auto &[primo,expoente]: pares){
        pii novo = {primo,k-expoente};
        ans.push_back(novo);
    }
    return ans;
}

int main() {
    int n, k; cin >> n >> k;
    vector<vector<pii>> nums;
    map<vector<pii>, int> mapa;
    for(int i=0;i<n;i++){
        int a; cin >> a; 
        vector<pii> atual = fatoracao(a,k);
        nums.push_back(atual);
        mapa[atual]++;
    }
    long long sum = 0;
    for(auto &[chave,value]: mapa){
        if(value == 0) continue;
        auto complemento = complementar(chave,k);
        if(!mapa.count(complemento)) continue;
        if(chave == complemento){
            sum += 1LL * mapa[chave] * (mapa[chave]-1) / 2;
            mapa[chave] = 0;
        } else {
            sum += 1LL * mapa[chave] * mapa[complemento];
            mapa[chave] = 0;
            mapa[complemento] = 0;
        }
    }
    cout << sum << endl;
}