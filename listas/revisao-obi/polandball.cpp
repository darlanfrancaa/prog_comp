#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    vector<int> root(n+1);
 
    int contador = 0;
    for(int i=1;i<=n;i++){
        int r = v[i];
        if(root[r] == 0){
            root[r] = 1;
            contador++;
            int other = v[r];
            root[other] = 1;
        }
    }
    cout << contador << "\n";
    return 0;
}