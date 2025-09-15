#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int di[4] = {1,-1,0,0};
int dj[4] = {0, 0, 1, -1};

bool dentro(int i, int j){
    return (i>=1 && i <= 7 && j>=1  &&  j<= 7);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    char matriz[8][8];
    for(int i=1;i<=7;i++){
        for(int j=1;j<=7;j++){
            cin >> matriz[i][j];
        }
    }
    int contador = 0;
    for(int i=1;i<=7;i++){
        for(int j=1;j<=7;j++){
            if(matriz[i][j] == 'o'){
                for(int k=0;k<4;k++){
                    int i1 = i + di[k], i2 = i1 +di[k];
                    int j1 = j + dj[k], j2 = j1 + dj[k];
                    if(dentro(i1,j1) && dentro(i2,j2)){
                        if(matriz[i1][j1] == 'o' && matriz[i2][j2] == '.') contador++;
                    }
                }
            }
        }
    }
    cout << contador << "\n";

    return 0;
}