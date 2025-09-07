#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link : https://neps.academy/br/exercise/276

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> oitavas; 
    for(int i=0;i<8;i++){
        int a, b; cin >> a >> b; 
        if(a > b) oitavas.push_back(2*i);
        else oitavas.push_back(2*i + 1);
    }
    vector<int> quartas;
    for(int i=0;i<4;i++){
        int a,b; cin >> a >> b;
        if(a > b) quartas.push_back(oitavas[2*i]);
        else quartas.push_back(oitavas[2*i+1]);
    }
    vector<int> semis;
    for(int i=0;i<2;i++){
        int a,b; cin >> a >> b;
        if(a > b) semis.push_back(quartas[2*i]);
        else semis.push_back(quartas[2*i+1]);
    }
    int a, b; cin >> a >> b; 
    int w;
    if( a > b) w = semis[0];
    else w = semis[1];
    char w_char = w + 'A';
    cout << w_char << "\n";
    return 0;
}