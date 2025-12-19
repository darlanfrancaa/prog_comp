#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXM = 1e18+5;
int bbin(int l, int r, function<bool(int)> f){
    r++;
    while(l < r){
        int mid = l + (r-l)/2;
        if(f(mid)) r = mid;
        else l = mid+1;
    }
    return l;
}

void gerar_produtos(int prod_atual, int idx, const vector<int> &primos, vector<int> &res){
    res.push_back(prod_atual);
    for(int i = idx; i<primos.size();i++){
        if(prod_atual >  MAXM / primos[i]) break;
        gerar_produtos(prod_atual * primos[i], i, primos, res); 
    }       
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> primos1, primos2;
    for(int i=0;i<n;i++){
        int p; cin >> p; 
        if(i%2 == 0) primos1.push_back(p);
        else primos2.push_back(p);
    }

    vector<int> prod1; 
    vector<int> prod2; 
    gerar_produtos(1,0, primos1, prod1);
    gerar_produtos(1,0, primos2, prod2);

    sort(prod1.begin(), prod1.end());
    sort(prod2.begin(), prod2.end());

    int k; 
    cin >> k; 
    auto test = [&](int x){
        int quantidade = 0;
        int ponteiro1 = lower_bound(prod1.begin(), prod1.end(),x) - prod1.begin(); // indice para o primeiro elemento que é maior ou igual a x;
        if(ponteiro1 == prod1.size()) ponteiro1--; // vou descendo o ponteiro até encontrar os valores que são bons

        for(int produto : prod2){
            if(produto > x) break; // então todos os próximos seriam maiores do que x
            while(ponteiro1 >= 0 && prod1[ponteiro1] > x / produto) ponteiro1--; // eu paro apenas quando for um produto menor que x
            if(ponteiro1 < 0) break;
            quantidade += ponteiro1 + 1; // se eu parei em um certo ponteiro x, todos os valores de 0 a x são válidos, então eu aumento essa quandidade;
        }

        return quantidade >= k; // vai retornar verdadeiro se a quantidade de produtos for maior ou igual a k
    };

    cout << bbin(1,MAXM, test) << "\n";
    return 0;
}