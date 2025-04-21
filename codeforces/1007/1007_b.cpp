#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
using ll = long long;
 
bool qp(ll x) { 
    auto y = round(sqrt(x));
    return y * y == x;
}
 
 
int main() {
    int k; cin >> k; 
    while (k > 0) {
        ll n; cin >> n;
        ll s = 0, it = 1;
        vector<ll> ans(n + 1);
        ll sq = ((n * (n + 1)) / 2);
        if (qp(sq)) {
            cout << "-1" << endl;
            k--;
            continue;
        }
        while (it <= n) {
            s += it;
            if (!qp(s)) {
                ans[it] = it;
                it++;
            }
            else {
                if (it == n) {
                    ans[it] = it;
                    it++;
                }
                else {
                    s += it + 1;
                    ans[it] = it + 1;
                    ans[it + 1] = it;
                    it += 2;
                }
            }
        }
 
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        k--;
    }
 
    return 0;
}