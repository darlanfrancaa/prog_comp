#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1010;
int n;
char matriz[MAXN][MAXN];
const int R_CHANGE[]{0, 1, 0, -1};
const int C_CHANGE[]{1, 0, -1, 0};

pair<int,int> bfs(int i, int j,vector<vector<bool>> &visitado){
    queue<pair<int,int>> fila; 
    int area = 0, perimetro = 0;
    fila.push({i,j});
    while(!fila.empty()){
        auto [xi,xj] = fila.front(); fila.pop();
        if(visitado[xi][xj]) continue;
        visitado[xi][xj] = true;
        area++;
        int contador = 0;
        for(int k=0;k<4;k++){
            int yi = xi + R_CHANGE[k];
            int yj = xj + C_CHANGE[k];
            if (yi >= 0 && yi < n && yj >= 0 && yj < n){
                if(matriz[yi][yj] == '#'){
                    fila.push({yi,yj});
                    contador++;
                }
            }
        }
        perimetro += (4-contador);
    }
    return {area, perimetro};
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n; 
    vector<vector<bool>> visitado (n,vector<bool> (n,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> matriz[i][j];
        }
    }
    int max_area = 0;
    int min_perimetro = INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matriz[i][j] != '#' or visitado[i][j]) continue;
            auto [area, perimetro] = bfs(i,j,visitado);
            if(area > max_area || (area == max_area && perimetro < min_perimetro)){
                max_area = area;
                min_perimetro = perimetro;
            }
        }
    }
    cout << max_area << " " << min_perimetro << endl;
    return 0;
}