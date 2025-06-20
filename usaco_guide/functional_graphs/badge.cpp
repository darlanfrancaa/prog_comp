#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int floyd(vector<int> &funcao, int inicio){
    int a = funcao[inicio]; 
    int b = funcao[a];
    while(a != b){
        a = funcao[a];
        b = funcao[funcao[b]];
    }
    a = inicio;
    while (a != b){
        a = funcao[a];
        b = funcao[b];
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector <int> funcao(n);
    for(int i=0;i<n;i++){
        int a; cin >> a;
        funcao[i] = a-1;
    }
    for(int i=0;i<n;i++){
        int ans = floyd(funcao, i);
        cout << ans + 1 << " ";
    }

    return 0;
}