#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int n, m; 
vector<vector<pair<int,char>>> grafo;
vector<int> color;

void bfs(int v, int cor) {
    queue<int> q;
    q.push(v);
    color[v] = cor;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto [w, carac] : grafo[u]) {
            if (color[w] == -1) {
                color[w] = cor;
                q.push(w);
            }
        }
    }
}

bool eh_possivel(vector<vector<pair<int,char>>>& grafo,int n) {
    vector<int> cor_1(n, -1);
    for (int i = 0; i < n; i++) {
        if (cor_1[i] == -1) {
            queue<int> q;
            q.push(i);
            cor_1[i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto [v, carac] : grafo[u]) {
                    if (cor_1[v] == -1) {
                        if (carac == 'S') cor_1[v] = cor_1[u];
                        else if (carac == 'D') cor_1[v] = 1 - cor_1[u];
                        q.push(v);
                    } 
                    else {
                        if (carac == 'S' && cor_1[v] != cor_1[u]) return false;
                        else if (carac == 'D' && cor_1[v] == cor_1[u]) return false;
                    }
                }
            }
        }       
    }
    return true;
}

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    grafo.resize(n);
    color.resize(n, -1); 
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        int u, v;
        cin >> u >> v;
        u--; v--;
        grafo[u].push_back({v, c});
        grafo[v].push_back({u, c});
    }
    int cor = 0;
    if (!eh_possivel(grafo,n)) {
        cout << "0" << endl;
        return 0;
    } else {
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                bfs(i, cor);
                cor++;
            }
        }
        string ans = "1";
        for (int i = 0; i < cor; i++) {
            ans += "0";
        }
        cout << ans << endl;
        return 0;
    }
}