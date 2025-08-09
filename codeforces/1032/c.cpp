#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int a, b; cin >> a >> b; 
        vector<vector<int>> matriz(a,vector<int>(b));
        int maximo = INT_MIN; 
        vector<pii> posicoes;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++) {
                int k; cin >> k;
                matriz[i][j] == k;
                if(k > maximo){
                    maximo = k; 
                    posicoes.clear();
                }
                if(maximo == k){
                    posicoes.push_back({i,j});
                }

            }
        }

        int r = posicoes[0].first; 
        int c = posicoes[0].second;
        set<int> primeiros,segundos;
        for(int i=0;i<posicoes.size();i++){
            if(posicoes[i].first != r) segundos.insert(posicoes[i].second);
            if(posicoes[i].second != c) primeiros.insert(posicoes[i].first);
        }
        if(primeiros.size() <= 1 || segundos.size() <= 1) cout << maximo - 1 << endl; 
        else cout << maximo << endl; 
        
        
    }
    return 0;
}