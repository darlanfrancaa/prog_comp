#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        string l,r; cin >> l >> r; 
        if(l == r){ 
            cout << 2 * l.size() << "\n";
            continue;
        }
        int qntd = 0; 
        while(qntd < l.size() && l[qntd] == r[qntd]) qntd++;
        if(r[qntd] - l[qntd] >= 2 ) {
            cout << 2 * qntd << "\n";
        }
        else { 
            int ans = 2 * qntd + 1; 
            for(int i = qntd +1 ; i<l.size();i++){
                if(l[i] == '9' && r[i] == '0') ans++;
                else break;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}