#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    float consumo,distancia,antes; cin >> consumo >> distancia >> antes; 
    float necessario = static_cast<float> (distancia) / consumo;
    cout << fixed << setprecision(1);
    
    float ans = necessario - antes > 0 ? necessario - antes : 0.0;
    cout << ans << endl; 
    return 0;
}