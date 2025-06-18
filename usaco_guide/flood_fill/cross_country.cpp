#include <bits/stdc++.h>
using namespace std;
int n , m;
const int MAXN = 510;
int elevation[MAXN][MAXN];
int waypoint[MAXN][MAXN];
const int R_CHANGE[]{0, 1, 0, -1};
const int C_CHANGE[]{1, 0, -1, 0};

bool bfs(int i, int j, int dist, vector<vector<bool>> &visitado){
    queue<pair<int,int>> fila;
    fila.push({i,j});
    while(!fila.empty()){
        auto [r,c] = fila.front(); fila.pop();
        if (r<0 || r>= n || c< 0 || c>= m) continue;
        if (visitado[r][c]) continue;
        visitado[r][c] = true;
        for(int k=0;k<4;k++){
            int r1 = r + R_CHANGE[k];
            int c1 = c + C_CHANGE[k];
            if(abs(elevation[r1][c1] - elevation[r][c]) <= dist) fila.push({r1,c1});
        }

    }
    for(int i1=0;i1<n;i1++){
        for(int j1=0;j1<m;j1++){
            if(waypoint[i1][j1] == 1 && !visitado[i1][j1]) return false;
        }
    }
    return true;
}

int main() {
    freopen("ccski.in", "r", stdin);
	freopen("ccski.out", "w", stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> elevation[i][j];
        }
    }
    bool primeiro = false;
    int a,b;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> waypoint[i][j];
            if(waypoint[i][j] == 1 && primeiro == false){
                primeiro = true;
                a = i, b = j;
            }
        }
    }
    int left = 0, right = 1e9;
    while(left<right){
        vector<vector<bool>> visitado(n,vector<bool>(m,false));
        int mid = (left + right)/2;
        if(bfs(a,b,mid,visitado)) right = mid;
        else left = mid+1;
    }
    cout << left << endl;
    


}