#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

ll distancia(pii &a, pii &b){
    ll dx = a.first - b.first; 
    ll dy = a.second - b.second; 
    ll ret = dx * dx + dy * dy;
    return ret;
}

int main() {
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m; 
    vector<pii> h(n);
    for(auto &value: h) cin >> value.first >> value.second; 
    vector<pii> g(m);
    for(auto &value: g) cin >> value.first >> value.second; 
    vector<vector<ll>> dp1(n+1, vector<ll>(m+1,INT_MAX));
    vector<vector<ll>> dp2(n+1, vector<ll>(m+1,INT_MAX));
    dp1[1][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i>1){
                dp1[i][j] = min(dp1[i][j], dp1[i-1][j] + distancia(h[i-1], h[i-2]));
            }
            if(j>1){
                dp2[i][j] = min(dp2[i][j], dp2[i][j-1] + distancia(g[j-1], g[j-2]));
            }
            if(i>0 && j > 0) {
                dp1[i][j] = min(dp1[i][j], dp2[i-1][j] + distancia(h[i-1], g[j-1]));
                dp2[i][j] = min(dp2[i][j], dp1[i][j-1] + distancia(h[i-1], g[j-1]));
            }

        }
    }
    cout << dp1[n][m] << endl;
    return 0;
}