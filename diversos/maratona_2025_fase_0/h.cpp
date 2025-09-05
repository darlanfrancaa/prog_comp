#include <iostream>

using namespace std;
using int64 = long long;

int64 qntd_b2(int64 k){
    if (k == 0) return 0; 
    int64 contador = 0;
    while(k > 0){
        k >>= 1;
        contador++;
    }
    return contador;
}
#define int int64

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n; 
    
    int k = qntd_b2(n);
    int atual = 0;

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }
    if (n == (1LL<<(k-1))) {
        cout << n - 1 << "\n";
        return 0;
    }
    int prox ;
    if(k%2 == 0){
        for(int i=0;i<k/2;i++){
            prox = atual ^ (1LL << i) ^ (1LL << k-1-i); 
            if(prox <= n) atual = prox;
        }
    } else { 
        for(int i=0;i<k/2;i++){
            prox = atual ^ (1LL << i) ^ (1LL << k-1-i); 
            if(prox <= n) atual = prox;
        }
        if((atual ^ (1LL<<(k/2))) <= n) atual = (atual ^ (1LL << (k/2)));
    }


    cout << atual << "\n";
    return 0;
}