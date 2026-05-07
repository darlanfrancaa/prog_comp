#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int qtd_even(int a, int b){
    if(a > b) return 0;
    int res = (b - a) / 2;
    if(abs(a) % 2 == 0 || abs(b) % 2 == 0) res++;
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int l,r; cin >> l >> r; 
    int d, u; cin >> d >> u; 
    int qtd = 0; 
    
    for(int x = l; x <= r; x++){
        int ax = abs(x);
        int menor_y = max(d, ax + 1);
        int maior_y = u;
        qtd += qtd_even(menor_y, maior_y);
        menor_y = d;
        maior_y = min(u, -ax - 1);
        qtd += qtd_even(menor_y, maior_y);
        if(ax % 2 == 0){
            menor_y = max(d, -ax);
            maior_y = min(u, ax);
            if(menor_y <= maior_y){
                qtd += maior_y - menor_y + 1;
            }
        }
    }
    cout << qtd << "\n";
    
    return 0;
}