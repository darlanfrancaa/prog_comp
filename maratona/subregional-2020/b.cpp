#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

const int N = 11;
int tab[N][N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    bool ok = true;
    for(int i=0;i<n;i++){
        int d, l, r, c; cin >> d >> l >> r >> c;
        if(d == 0){
            for(int j=0; j<l;j++){
                int ri = r; 
                int ci = c + j;
                if(ri > 10 || ci > 10 || tab[ri][ci] == 1) {
                    cout << "N"; 
                    return 0;
                } else {
                    tab[ri][ci] = 1;
                }
            }
        }
        if(d == 1){
            for(int j=0; j<l;j++){
                int ri = r + j; 
                int ci = c;
                if(ri > 10 || ci > 10 || tab[ri][ci] == 1) {
                    cout << "N"; 
                    return 0;
                } else {
                    tab[ri][ci] = 1;
                }
            }
        }
    }
    cout << "Y";
    return 0;
}