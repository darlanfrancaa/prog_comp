#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        map<int,int> color; 
        vector<int> cores;
        for(int i=0;i<n;i++){
            int a; cin >> a; 
            color[a]++; 
            cores.push_back(a);
        }
        int qntd = color.size(); 
        int ans = LLONG_MAX;
        for(int i=0;i<cores.size();i++){
            if(cores[i] >= qntd && cores[i] < ans) ans = cores[i];
        }
        cout << ans << "\n";
    }
    return 0;
}