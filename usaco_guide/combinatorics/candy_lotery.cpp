#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n, k; cin >> n >> k; 
    double valor_esperado = 0; 
    for(int i=1;i<= k; i++){
        valor_esperado += i*(pow((double)i/k, n) - (pow((double)(i-1)/k, n)));
    }
    cout << setprecision(6) << fixed;
    cout << valor_esperado << endl;
}