#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;

// Solução está errada e eu não sei onde está o erro


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    ll a, b; 
    cin >> n >> a >> b;

    vector<ll> p(n); 
    map<ll, int> pos;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    vector<int> ans(n, -1);
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        bool parceiro_a = pos.count(a - p[i]);
        bool parceiro_b = pos.count(b - p[i]);

        if (!parceiro_a && !parceiro_b) {
            cout << "NO" << endl;
            return 0;
        }
        if (!parceiro_a) {
            if (ans[i] == -1) {
                ans[i] = 1;
                q.push(i);
            }
        }
        if (!parceiro_b) {
            if (ans[i] == -1) {
                ans[i] = 0;
                q.push(i);
            }
        }
    }

    auto process_queue = [&]() -> bool {
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ll valor = p[u];
            int conj = ans[u];

            ll valor_parceiro;
            int parceiro_idx;

            if (conj == 0) {
                valor_parceiro = a - valor;
                if (!pos.count(valor_parceiro)) return false;
                parceiro_idx = pos[valor_parceiro];
                if (ans[parceiro_idx] == 1) return false;
                if (ans[parceiro_idx] == -1) {
                    ans[parceiro_idx] = 0;
                    q.push(parceiro_idx);
                }
            } else { // conj == 1
                valor_parceiro = b - valor;
                if (!pos.count(valor_parceiro)) return false;
                parceiro_idx = pos[valor_parceiro];
                if (ans[parceiro_idx] == 0) return false;
                if (ans[parceiro_idx] == -1) {
                    ans[parceiro_idx] = 1;
                    q.push(parceiro_idx);
                }
            }
        }
        return true;
    };

    if (!process_queue()) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            ans[i] = 0;
            q.push(i);
            if (!process_queue()) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}