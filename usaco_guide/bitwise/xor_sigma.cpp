#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> vetor(n);
    for(auto &num: vetor) cin >> num; 
    long long sum = 0;
    for(int i=0;i<n;i++) sum -= vetor[i];
    for(int i=0;i<30;i++){
        int atual = 0; //vai armazenar o valor do xor-sum bit que estamos analizando
        vector<int> prefix = {1,0}; // vai armazenar quantos bits 1, 0 tivemos na prefix xor-sum até o momento
        for(auto num: vetor){
            atual ^= (num >> i) & 1; // pega o valor do bit;
            /*isso conta quantas subsequencias terminam nesse cara para o bit i, isso está correto porque só dá 1 na soma final se existe uma 
            paridade impar de 1's até o momento e para calcular isso calculamos qual a paridade de 1 antes disso
            */
            sum += prefix[atual^1] * 1LL << i; 
            prefix[atual]++;
        }
    }
    cout << sum << "\n";
    return 0;
}