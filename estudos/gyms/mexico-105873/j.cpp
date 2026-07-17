#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: 

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    if(!(cin >> n)) return 0;

    vector<int> primeira_pos(1 << 26, -1);
    
    int mask_atual = 0;
    primeira_pos[0] = 0;
    
    string s; cin >> s; 
    int ans = 1;
    
    for(int i = 0; i < s.size(); i++){
        mask_atual ^= (1 << (s[i] - 'a'));
        int pos_atual = i + 1;
        if(primeira_pos[mask_atual] != -1) {
            ans = max(ans, pos_atual - primeira_pos[mask_atual]);
        } else {
            primeira_pos[mask_atual] = pos_atual;
        }
        for(int j = 0; j < 26; j++){
            int new_mask = mask_atual ^ (1 << j);
            if(primeira_pos[new_mask] != -1) {
                ans = max(ans, pos_atual - primeira_pos[new_mask]);
            }
        }
    }
    
    cout << ans << "\n";

    return 0;
}