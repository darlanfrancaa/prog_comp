#include <bits/stdc++.h>

using namespace std; 

int n, m, k; 
vector<vector<int>> ans;
vector<int> UP = {-1, 0}, DOWN = {1, 0}, LEFT = {0, -1}, RIGHT = {0, 1};
vector<vector<int>> anti_horario = {UP, LEFT, DOWN, RIGHT};
vector<vector<int>> horario = {UP, RIGHT, DOWN, LEFT};

void spiral(int r, int c , bool sentido_atual){
    vector<vector<int>> sentido = sentido_atual ? anti_horario : horario;
    int idx_distancia = 0, tamanho = 1, restantes = 1, quantidade_total = 1, contador_dentro = 0; 
    bool vai_aumentar = false;
    while(contador_dentro < n*m){
        bool esta_fora = r < 0 || c < 0 || r >= n || c >= m;
        if(!esta_fora){
            ans[r][c] = min(ans[r][c],quantidade_total);
            contador_dentro++;
        }
        quantidade_total++;
        r += sentido[idx_distancia][0];
        c += sentido[idx_distancia][1];
        restantes--;
        if(restantes==0) {
            if(vai_aumentar) tamanho++;
            idx_distancia = (idx_distancia + 1) % 4;
            restantes = tamanho;
            vai_aumentar = !vai_aumentar;
        }
    }
}


int main(){
    cin >> n >> m >> k;
    ans = vector<vector<int>> (n,vector<int>(m,1e9));
    for(int i=0; i<k; ++i){
        int r,c,t;
        cin >> r >> c >> t;
        spiral(r-1,c-1,t);
    }
    for(auto& linha : ans){
        for(int casa : linha) cout << casa << " ";
        cout << endl;
    }
    return 0;
}