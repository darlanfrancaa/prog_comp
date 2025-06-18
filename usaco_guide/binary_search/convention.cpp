#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
int n, m , c;
vector<int> cows;

bool its_possible(int k){
    int bus = 0, inicio = 0, fim = 0;
    while(fim < n){
        if(inicio == fim) bus++; // aumento um na quantidade de oninus quando forem iguais
        if(cows[fim] - cows[inicio] > k) inicio = fim; // se essa condicao acontece, entao eles nao podem estar no mesmo bus 
        else if(fim - inicio + 1 == c) inicio = ++fim; // aqui o onibus encheu e incio recebe fim++ de modo que fim ficou no onibus anterior         
        else fim++;
    }
    return bus <= m;
} 

// essa funcao ve se é possivel que formar os m onibus de modo que cada onibus nao tenha ninguem com diferenca pelo menos k


int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> c;
    cows.resize(n);
    for(auto &cow: cows) cin >> cow;
    sort(cows.begin(),cows.end());
    int left = 0, right = 1e9;
    while(left < right){
        int mid = left + (right - left)/2;
        if(its_possible(mid)) right = mid;
        else left = mid + 1;
    }
    cout << left << endl;
    return 0;
}