#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

struct Cow{
    int height, weight, strenght; 
};

signed main() {
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);

    int n,h; cin >> n >> h; 
    vector<Cow> cows(n);
    for(auto &c:cows){
        cin >> c.height >> c.weight >> c.strenght;
    }
    vector<int> dp((1<<n));
    dp[0] = LLONG_MAX;
    for(int mask = 1; mask < (1<<n) ; mask++){
        dp[mask] = -1;
        for(int i=0;i<n;i++){
            if(mask & (1<<i)){
                int prev = mask ^ (1 << i);
                if(dp[prev] != -1 && dp[prev] >= cows[i].weight){
                    int new_ans = min(dp[prev]-cows[i].weight,cows[i].strenght);
                    dp[mask] = max(dp[mask], new_ans);
                }
            }
        }
    }
    int ans = -1; 
    for(int mask = 1; mask < (1<<n); mask++){
        int altura = 0; 
        if(dp[mask] != -1){
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    altura += cows[i].height;
                }
            }
        }
        if(altura >= h){
            ans = max(ans, dp[mask]);
        }
    }
    if(ans > -1){
        cout << ans << "\n";
    } else { 
        cout << "Mark is too tall\n";
    }
    return 0;
}