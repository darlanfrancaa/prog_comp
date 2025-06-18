#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s; 
    int tamanho = s.size();
    map<int,int> mapa;
    mapa[0] = 1;
    int new_number = 0, potencia_de_10 = 1;
    long long ans = 0;

    for(int i=tamanho-1;i>=0;i--){
        int num = s[i] - '0';
        new_number = (new_number + num * potencia_de_10) % 2019;
        ans += mapa[new_number];
        mapa[new_number]++;
        potencia_de_10 = (potencia_de_10*10) % 2019;
    }
    cout << ans << endl; 
    return 0;
}