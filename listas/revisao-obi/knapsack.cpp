#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link : https://codeforces.com/contest/1446/problem/A

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n, w; cin >> n >> w; 
        vector<pii> v(n+1);
        for(int i=1;i<=n;i++) {
            int a; cin >> a; 
            v[i] = {a, i};
        }
        int peso; 
        peso = (w % 2 == 0) ? w/2 : w/2 + 1;
        vector<pii> sorted = v;
        sort(sorted.begin() + 1, sorted.end());
        int pref[n+1];
        vector<int> ans;
        int idx = 0;
        pref[0] = 0; 
        for(int i=1;i<=n;i++) {
            pref[i] = pref[i-1] + sorted[i].first;
            if(pref[i] >= peso && pref[i]<= w){
                for(int j=1;j<=i;j++){
                    ans.push_back(sorted[j].second);
                }
                break;
            } 
            else if(pref[i] > w) {
                idx = i;
                if(sorted[i].first >= peso && sorted[i].first <= w){
                    ans.push_back(sorted[i].second);
                } else { 
                    ans.clear();
                }
                break;
            }
        }
        if(ans.size() == 0){ 
            cout << -1 << "\n";
            continue;
        } else {
            cout << ans.size() << "\n";
            for(auto &v: ans) cout << v << " ";
            cout << "\n";
            continue;
        }
    }
    return 0;
}