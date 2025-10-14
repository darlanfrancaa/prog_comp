#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int x, n; cin >> x >> n; 
    set<int> traffics;
    multiset<int> distances; 
    traffics = {0,x};
    distances = {x};
    for(int i=0;i<n;i++){
        int a; cin >> a; 

        auto it = traffics.lower_bound(a);
        int right = *it; 
        int left = *prev(it);

        // printf("o valor do sinal esquerda %lld e o a direita foi %lld com distancia \n", left, right);

        distances.erase(distances.find(right - left));

        distances.insert(a - left);
        distances.insert(right - a);

        traffics.insert(a);

        cout << *distances.rbegin() << " ";
    }
    return 0;
}