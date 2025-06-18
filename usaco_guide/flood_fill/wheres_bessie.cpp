#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 20;
vector<vector<char>> matriz(MAXN,vector<char>(MAXN));
vector<vector<bool>> visitado(MAXN,vector<bool>(MAXN));

struct PCL {
    int i1, j1;
    int i2, j2;
};

bool dentro(PCL &a, PCL &b){
    return (a.i1 >= b.i1 && a.i2 <= b.i2 && a.j1 >= b.j1 && a.j2 <= b.j2);
}
int i_min, i_max, j_min, j_max;

void dfs(int i, int j, char cor){
    if(i < i_min || j < j_min || i > i_max || j > j_max) return;
    if(visitado[i][j] || matriz[i][j] != cor) return;
    visitado[i][j] = true;
    dfs(i+1, j, cor);
    dfs(i-1, j, cor);
    dfs(i, j+1, cor);
    dfs(i, j-1, cor);
}

bool eh_pcl(int i1, int j1, int i2, int j2){
    vector<int> cores(26);
    i_min = i1 , i_max = i2 , j_min = j1 , j_max = j2;
    for(int i=i1;i<=i2;i++){
        for(int j=j1;j<=j2;j++){
            if(!visitado[i][j]){
                char cor = matriz[i][j];
                cores[cor-'A']++; // de modo que esse vetor armazene o numero de componentes conexas de uma certa cor no grafo
                dfs(i,j,cor);
            }
            
        }
    }
    fill(visitado.begin(), visitado.end(), vector<bool>(MAXN, false));
    int qntd_cores = 0;
    bool uma_comp = false, duas_comp = false;
    for(int i=0;i<cores.size();i++){
        if(cores[i] !=0) qntd_cores++;
        if(cores[i] == 1) uma_comp = true;
        if(cores[i] >= 2) duas_comp = true;
    }
    return (qntd_cores == 2 && uma_comp && duas_comp);
}



int main() {
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { 
            cin >> matriz[i][j]; 
        }
	}
    vector<PCL> lista_dos_pcl;
    for (int i1 = 0; i1 < n; i1++) {
		for (int j1 = 0; j1 < n; j1++) {
			for (int i2 = 0; i2 < n; i2++) {
				for (int j2 = 0; j2 < n; j2++) {
					if (eh_pcl(i1, j1, i2, j2)) {
						lista_dos_pcl.push_back({i1, j1, i2, j2});
					}
				}
			}
		}
	}
    int qntd_pcl = 0;
    for (int i = 0; i < lista_dos_pcl.size(); i++) {
		int verdade = 1;
		for (int j = 0; j < lista_dos_pcl.size(); j++) {
			if (i == j) { continue; }
			if (dentro(lista_dos_pcl[i],lista_dos_pcl[j])) {
				verdade = 0;
				break;
			}
		}
		qntd_pcl += verdade;
	}
    cout << qntd_pcl << endl;
    return 0;
}