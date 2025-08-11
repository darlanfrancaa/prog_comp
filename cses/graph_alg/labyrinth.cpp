#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
int di[4] = {0,1,0,-1};
int dj[4] = {-1,0,1,0};
char carac[4] = {'L', 'D', 'R', 'U'};
int n, m;
vector<vector<char>> tab;
vector<vector<int>> dist;
vector<vector<pii>> pai;
vector<vector<char>> op;

bool validar(int a, int b){
    return (a >= 0 && a<= n-1 && b >= 0 && b <= m-1 && tab[a][b] != '#');
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; 
    tab.resize(n,vector<char> (m));
    dist.resize(n,vector<int> (m,INT_MAX));
    pai.resize(n,vector<pii> (m));
    op.resize(n,vector<char>(m));
    pii a, b;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin >> tab[i][j];
            if(tab[i][j] == 'A') a = {i,j};
            if(tab[i][j] == 'B') b = {i,j};
        }
    queue<pii> q; 
    q.push(a);
    dist[a.first][a.second] = 0;

    while(!q.empty()){
        auto [vi,vj] = q.front(); q.pop();
        for (int k=0;k<4;k++){
            int ui = vi + di[k];
            int uj = vj + dj[k];
            if (validar(ui,uj) && dist[ui][uj] == INT_MAX){
                dist[ui][uj] = dist[vi][vj] + 1; 
                pai[ui][uj] = {vi,vj};
                op[ui][uj] = carac[k];
                q.push({ui,uj});
            }
        }
    }
    if(dist[b.first][b.second] == INT_MAX) cout << "NO" << endl; 
    else {
        cout << "YES" << endl << dist[b.first][b.second] << endl;
        // agora, para descobrir o caminho;
        vector<char> ans;
        pii atual = b;
        while(atual != a){
            ans.push_back(op[atual.first][atual.second]);
            pii last = pai[atual.first][atual.second];
            atual = {last.first, last.second};
        }
        reverse(ans.begin(), ans.end());
        for(auto c: ans) cout << c;
    }
    return 0;
}