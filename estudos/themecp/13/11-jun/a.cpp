#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link:

void solve(){
    vector<vector<char>> matriz(3, vector<char> (3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> matriz[i][j];
        }
    }
    for(int i=0;i<3;i++){
        if(matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2] && matriz[i][0] != '.') {
            cout << matriz[i][0] << "\n";
            return;
        }
        if(matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i] && matriz[0][i] != '.'){
            cout << matriz[0][i] << "\n";
            return;
        }
    }
    if(matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[0][0] != '.'){
        cout << matriz[0][0] << "\n";
        return;
    } 
    if(matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[1][1] != '.'){
       cout << matriz[1][1] << "\n";
       return;
    }
    cout << "DRAW\n";
    return;

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    
    return 0;
}