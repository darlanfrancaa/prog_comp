#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

const int M = (1LL << 61) - 1;
const int B = 9973;

__int128 multi(int a, int b){
    return (__int128)a*b;
}

int multimod(int a, int b){
    return multi(a,b) % M;
}

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);    
    string S, T; cin >> S >> T; 
    int k = T.size();

    string ans = "";
    vector<int> ans_hash;
    ans_hash.push_back(0);


    vector<int> pow = {1};
    while(pow.size() <= T.size()){
        pow.push_back(multimod(pow.back(), B));
    }

    int hash_t = 0; 
    for(char c: T){
        hash_t = (multimod(hash_t, B)+c)%M;
    }

    for(char c: S){
        ans += c;
        
        int last_hash = ans_hash.back();
        int new_hash = (multimod(last_hash,B) + c) % M;
        ans_hash.push_back(new_hash);

        if(ans.size() >= k){
            int curr_idx = ans_hash.size()-1; 
            int start_idx = curr_idx - k;

            int val = ans_hash[curr_idx] - multimod(ans_hash[start_idx],pow[k]);
            val = (val % M + M) % M;

            if(val == hash_t){
                ans_hash.resize(ans_hash.size() - k);
                ans.resize(ans.size() - k);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
