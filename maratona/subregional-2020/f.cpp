#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; 
    cin >> s; 
    int gl = 0, gr = 0;
    int pl = 0, pr = 0, sacador = 0;
    bool partida_encerrada = false;
    
    for(int i = 0; i < s.size(); i++){
        if (s[i] == 'Q') {
            if (partida_encerrada) {
                if (gl == 2) cout << gl << " (winner) - " << gr << "\n";
                else cout << gl << " - " << gr << " (winner)\n";
            } else {
                cout << gl << " (" << pl << (sacador == 0 ? "*" : "") << ") - " 
                     << gr << " (" << pr << (sacador == 1 ? "*" : "") << ")\n";
            }
        } 
        else if (!partida_encerrada) {
            if(s[i] == 'S'){ 
                if(sacador == 0) pl++;
                else pr++; 
            } 
            else if(s[i] == 'R'){ 
                if(sacador == 0){
                    pr++;
                    sacador = 1;
                } else {
                    pl++;
                    sacador = 0;
                }
            }
            bool venceu_esq = (pl >= 5 && (pl - pr) >= 2) || (pl == 10);
            bool venceu_dir = (pr >= 5 && (pr - pl) >= 2) || (pr == 10);
            
            if (venceu_esq) {
                gl++;
                if (gl == 2) {
                    partida_encerrada = true;
                } else {
                    pl = 0; 
                    pr = 0;
                    sacador = 0; 
                }
            } 
            else if (venceu_dir) {
                gr++;
                if (gr == 2) {
                    partida_encerrada = true;
                } else {
                    pl = 0; 
                    pr = 0;
                    sacador = 1; 
                }
            }
        }
    }
    
    return 0;
}