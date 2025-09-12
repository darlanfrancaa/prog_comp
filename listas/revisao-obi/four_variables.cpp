#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10; 

int maior_primo[N+1];
int qntd_div[N+1];

void fill_crivo(){
    for(int i=1;i<=N;i++){
        maior_primo[i] = i;
    }

    for(int i=2;i*i<=N;i++){
        if(maior_primo[i] == i){
            for(int j= i; j<=N;j+=i){
                maior_primo[j] = i;
            }
        }
    }
}

void fill_qntd(){
    qntd_div[1] = 1; 
    for(int i= 2;i<=N;i++){
        int p = maior_primo[i];
        int k = i, contador = 0;
        while(k%p == 0){
            k /= p;
            contador++;
        }
        qntd_div[i] = qntd_div[k] * (contador+1);
    }
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int sum = 0; 
    int n; cin >> n;
    fill_crivo();
    fill_qntd(); 
    for(int i=1;i<=n-1;i++){
        sum += qntd_div[i] * qntd_div[n-i];
    }
    cout << sum << "\n";
    return 0;
}