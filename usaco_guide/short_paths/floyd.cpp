#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

constexpr long long BIG = 1e18;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,q; cin >> n >> m >> q; 
    vector<vector<ll>> min_dist(n,vector<ll>(n, BIG));
    for(int i=0;i<m;i++){
        int a, b,c; cin >> a >> b >> c; 
        a--;b--;
        if(c < min_dist[a][b]) min_dist[a][b] = min_dist[b][a] = c;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ll new_dist = min_dist[i][k] + min_dist[k][j];
                if(new_dist < min_dist[i][j]){
                    min_dist[i][j] = min_dist[j][i] = new_dist;
                }
            }
        }
    }

    for(int i=0;i<q;i++){
        int a,b; cin >> a >> b; 
        a--;b--;
        if(a == b){
            min_dist[a][b] = 0;
        } else if(min_dist[a][b] == BIG){
            min_dist[a][b] = -1;
        }
        cout << min_dist[a][b] << "\n";
    }
    return 0;
}