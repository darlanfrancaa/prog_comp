#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> estrelas(n);
    ll soma = 0;
    for(auto &estrela : estrelas) {
        cin >> estrela;
        soma += estrela;
    }
    int atual = 0;
    int contador_estrelas = 0;
    int contador = 0;
    bool visitou_par = false;
    while(atual >= 0 && atual <= n-1){
        if(estrelas[atual] % 2 == 1) {
            estrelas[atual++]--;
            contador++;
            contador_estrelas++;
        }
        else if(estrelas[atual] % 2 == 0 && estrelas[atual] > 0){
            estrelas[atual--]--;
            contador++;
            if(!visitou_par) {
                visitou_par = true;
                contador_estrelas++;
            }
        } else break;
    }
    cout << contador_estrelas << " " << soma - contador << endl;

    return 0;
}