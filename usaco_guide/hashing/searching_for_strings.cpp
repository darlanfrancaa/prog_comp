#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

int freq_n[26], curr_freq[26];
string n,h;

class HashedString {
private:
    static const int M = (1LL << 61) - 1;
    static const int B;

    static vector<int> pow;
    vector<int> p_hash; 

    __int128 mul(int a, int b) {return ((__int128)a * b);}
    int mod_mul(int a, int b) {return mul(a,b) % M;}
public:
    HashedString(const string &s): p_hash(s.size()+1) {
        while(pow.size() <= s.size()) {
            pow.push_back(mod_mul(pow.back(),B));
        }
        p_hash[0] = 0; 
        for(int i = 0;i<s.size();i++){
            p_hash[i+1] = (mul(p_hash[i],B) + s[i]) % M;
        }
    }

    int get_hash(int start, int end){
        int value = p_hash[end+1] - mod_mul(p_hash[start], pow[end-start+1]);
        return (value + M) % M;
    }
};
vector<int> HashedString::pow = {1};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int HashedString:: B = uniform_int_distribution<int>(300,M-1)(rng);

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> h;
    if(n.size() > h.size()){
        cout << 0 << "\n";
        return 0;
    }
    HashedString hs(h) ;
    set<int> diferentes; 
    for(int i=0;i<n.size();i++){
        freq_n[n[i] - 'a']++;
        curr_freq[h[i] - 'a']++;
    }
    for(int i = n.size()-1; i<h.size();i++){
        if(i >= n.size()){
            curr_freq[h[i]-'a']++;
            curr_freq[h[i-n.size()]-'a']--;
        }
        bool same = true; 
        for(int j=0;j<26;j++){
            if(curr_freq[j] != freq_n[j]) same = false;
        }
        if(same) diferentes.insert(hs.get_hash(i+1-n.size(), i));
    }

    cout << diferentes.size() << "\n";
    return 0;
}