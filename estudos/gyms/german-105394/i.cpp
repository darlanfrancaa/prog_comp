#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/gym/105394/problem/I

struct Onda{
    int p, l, a; 
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, w; cin >> n >> w; 
    vector<Onda> ondas;
    for(int i=0;i<n;i++){
        char op; cin >> op; 
        if(op == '!'){
            int p, l ,a; cin >> p >> l >> a; 
            ondas.push_back({p,l,a});
        } else if (op == '?'){
            int x; cin >> x; 
            int ans = 0; 
            for(auto onda: ondas){
                if(x >= onda.p && x < onda.p + onda.l){
                    int dist = x - onda.p;
                    if(dist%4 == 0) ans += onda.a;
                    else if(dist%4 == 2) ans -= onda.a;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}