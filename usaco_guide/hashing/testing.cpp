#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

class HashedString{
private:
    const int M = 1e9+9; 
    const int B = 9973;

    static vector<int> pow; 
    vector<int> p_hash; 
public:
    HashedString(const string &s) : p_hash(s.size()+1) {
        while(pow.size() <= s.size()) pow.push_back((pow.back()*B) % M);
        p_hash[0] = 0; 
        // ou seja a primeira letra s[0] está sendo salva em p_hash[1];
        for(int i=0;i<s.size();i++){
            p_hash[i+1] = ((p_hash[i] * B) % M + s[i]) % M;
        }
    }

    int get_hash(int start, int end){
        int val = (p_hash[end+1] - (p_hash[start] * pow[end-start+1]));
        return (val % M + M) % M;
    }
};
vector<int> HashedString::pow = {1};

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    string texto = "bom dia"; 
    cout << HashedString(texto).get_hash(0, texto.size()-1);
    
    return 0;
}   