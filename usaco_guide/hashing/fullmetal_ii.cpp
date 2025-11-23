#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int MAXN = 12;

class HashedString { 
private: 
    static const int M = (1LL << 61) - 1;
    static const int B = 9973; 

    static vector<int> pow; 
    vector<int> p_hash; 

    __int128 multi(int a, int b){
        return (__int128)a*b;
    }

    int multimod(int a, int b){
        return multi(a,b) % M;
    }
public: 
    HashedString(const string& s): p_hash(s.size()+1){
        while(pow.size() <= s.size()){
            pow.push_back(multimod(pow.back(), B));
        }
        p_hash[0] = 0;
        for(int i=0;i<s.size();i++){
            p_hash[i+1] = (multimod(p_hash[i], B) + s[i]) % M;
        }    
    }

    int get_hash(int start, int end){
        int val = p_hash[end+1] - multimod(p_hash[start], pow[end-start+1]);
        return (val % M + M) % M;
    }
};
vector<int> HashedString:: pow = {1};

int adj[15][15];
vector<string> pal_fake, pal;

int calc_pref(int idx_a, int idx_b, HashedString &ha, HashedString &hb){
    int len_a = pal[idx_a].size();
    int len_b = pal[idx_b].size();

    for(int k=min(len_a, len_b); k>=1;k--){
        // checando se o suff de ha é o pref de hb para um valor k
        if(ha.get_hash(len_a-k, len_a-1) == hb.get_hash(0,k-1)){
            return k;
        }
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    pal_fake.resize(n);
    for(int i=0;i<n;i++) cin >> pal_fake[i];

    vector<bool> manter(n,true);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;

            if(pal_fake[j].find(pal_fake[i]) != string::npos){
                if(pal_fake[i] == pal_fake[j] && i < j) continue;
                manter[i] = false;
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(manter[i]) pal.push_back(pal_fake[i]);
    }

    n = pal.size(); 
    vector<HashedString> hashes;
    for(const string&s : pal) hashes.emplace_back(s);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = calc_pref(i,j,hashes[i], hashes[j]);
        }
    }

    vector<vector<int>> dp((1 << MAXN), vector<int>(MAXN+1,LLONG_MAX)); // eu criei uma dp[mask][v] que significa que eu terminei essa mask no vertice v

    for(int i=0;i<n;i++){
        dp[1<<i][i] = pal[i].size();
    }


    for(int mask = 1; mask < (1 << n); mask++){
        for(int i=0;i<n;i++){
            if(!(mask & (1 << i))) continue;
            if(dp[mask][i] == LLONG_MAX) continue;

            for(int j=0;j<n;j++){
                if(mask & (1<<j)) continue; 
                int new_mask = mask | (1 << j);
                int tamanho_adic = pal[j].size() - adj[i][j];
                dp[new_mask][j] = min(dp[new_mask][j],dp[mask][i] + tamanho_adic);
            }
        
        }
    }   

    int ans = LLONG_MAX;
    int all_bits = (1<<n)-1;
    for(int i=0;i<n;i++){
        ans = min(ans, dp[all_bits][i]);
    }

    cout << ans << "\n";
    return 0;
}