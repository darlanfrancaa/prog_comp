#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 10;
int vetor[MAXN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int k; cin >> k; 
        const int raiz = (int)sqrt(k);
        for(int div = 1; div <= raiz ; div++){
            if(k % div == 0){
                vetor[div]++;
                if(div != k/div) vetor[k/div]++;
            }
        }
    }
    for(int i=MAXN;i>=1;i--){
        if(vetor[i] >= 2) {
            cout << i << endl; 
            break;
        }
    }
    return 0;
}