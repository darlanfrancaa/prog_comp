#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int e,m,d; cin >> e >> m >> d; 
    vector<pii> juntos, separados; 
    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b; 
        juntos.push_back({a,b});
    }
    for(int i=0;i<d;i++){
        int a,b; cin >> a >> b;
        separados.push_back({a,b});
    }
    vector<int> grupo(e+1); 
    for(int i=0;i<e/3;i++){
        for(int j=0;j<3;j++){
            int a; cin >> a; 
            grupo[a] = i+1;
        }
    }
    int contador = 0; 
    for(auto par: juntos){
        if(grupo[par.first] != grupo[par.second]) {
            contador++;
            cout << par.first << " " << par.second << "nao estao juntos" << endl;
        }
    }
    for(auto par: separados){
        if(grupo[par.first] == grupo[par.second]) {
            contador++;
            cout << par.first << " " << par.second << endl;
        }
    }
    cout << contador << endl;
    return 0;
}