#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
 
bool compara(int a, int b) {
    return a > b;
}
 
 
int main() {
    int t; cin >> t; 
    while(t>0){
        t--;
        int n; cin >> n; 
        vector<int> v(n);
        for(auto &c : v) cin >> c;
        unordered_map<int,vector<int>> componentes;
        for(int i=0;i<n;i++) {
            int diff = i - v[i] + 1;
            componentes[diff].push_back(v[i]);
        }
        // for(auto &[chave, valor]: componentes){
        //     cout << chave << endl;
        //     for(int _: valor) cout << _ + 1<< " ";
        //     cout << endl;
        // }
        long long soma = 0;
        for(auto &[diff,vetor] : componentes){
            sort(vetor.begin(),vetor.end(),compara);
            for(int i=0; i<int(vetor.size())-1;i+=2){
                if(vetor[i]+vetor[i+1] > 0){
                    soma += vetor[i] + vetor[i+1];
                }
            }
        }
        cout << soma << endl;
    }
}