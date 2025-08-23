#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <algorithm>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<vector<int>> filhos;
    vector<vector<int>> adj;
    queue<int> q;
    int n;

    DSU(int num_vacas) {
        n = num_vacas;

        parent.resize(n + 1);
        filhos.resize(n + 1);
        adj.resize(n + 1);

        iota(parent.begin(), parent.end(), 0);
        for (int i = 1; i <= n; i++) {
            filhos[i].push_back(i);
        }
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]); 
    }

    void add_edge(int cow1, int cow2) {
        adj[cow1].push_back(cow2);
    }

    void merge(int a, int b) {

        int ra = find(a);
        int rb = find(b);

        if (ra == rb) return;

        if (filhos[ra].size() < filhos[rb].size()) swap(ra, rb);

        for (int filho : filhos[rb]) {
            parent[filho] = ra;
            filhos[ra].push_back(filho);
        }
        filhos[rb].clear();

        adj[ra].insert(adj[ra].end(), adj[rb].begin(), adj[rb].end());
        adj[rb].clear();

        if (adj[ra].size() > 1) {
            q.push(ra);
        }
    }

    vector<int> solve() {

        for (int i = 1; i <= n; i++) {
            if (adj[i].size() > 1) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            while (adj[v].size() > 1) {
                int a = adj[v].back();
                adj[v].pop_back();
                int b = adj[v].back(); 

                if (find(a) != find(b)) {
                    merge(a, b);
                }
            }
        }

        vector<int> ans(n + 1);
        vector<int> cores_raiz(n + 1, 0);
        int cor = 1;
        
        for (int i = 1; i <= n; i++) {
            int r = find(i); 
            if (cores_raiz[r] == 0) {
                cores_raiz[r] = cor++;
            }
            ans[i] = cores_raiz[r];
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    freopen("fcolor.in", "r", stdin);
    freopen("fcolor.out", "w", stdout);
    int n, m; cin >> n >> m;
    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        dsu.add_edge(a, b);
    }

    vector<int> resp = dsu.solve();

    for (int i = 1; i <= n; i++) {
        cout << resp[i] << "\n";
    }
    return 0;
}