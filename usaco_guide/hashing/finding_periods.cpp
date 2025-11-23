#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

class HashingStrings{
private:
    static const int M = (1LL << 61) - 1; 
    static const int B = 9973;

    static vector<int> pow;
    vector<int> p_hash; 

    __int128 multi(int a, int b){
        return (__int128)a *b;
    }

    int multimod(int a, int b){
        return multi(a,b) % M;
    }
public: 
    HashingStrings(const string& s): p_hash(s.size()+1){
        while(pow.size() <= s.size()){ 
            pow.push_back(multimod(pow.back(), B));
        }
        p_hash[0] = 0; 
        for(int i=0;i<s.size();i++){
            p_hash[i+1] = (multimod(p_hash[i], B) + s[i]) % M;
        }
    }

    int get_hash(int start, int end){
        int value = p_hash[end+1] - multimod(p_hash[start],pow[end-start+1]);
        return (value + M) % M;
    }
};

vector<int> HashingStrings:: pow = {1};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    HashingStrings hs(s);
    for(int k = 1; k <= s.size(); k++){
        // faremos a operação apenas no caso em que k é divisor do tamanho da string;
        // printf("agora eu estou analisando o valor k %lld \n dentro: \n", k);
        int first_substring = hs.get_hash(0,k-1);
        int i = k; 
        bool same = true;
        while(i < s.size()){
            int proximo = min((int)s.size()-1, i+k-1); // isso aqui nos dá o próximo até o final
            int diff = proximo - i;
            int next_substring = hs.get_hash(i, proximo); 
            // printf("agora eu estou analisando o intervalo i %lld e proximo %lld\n", i, proximo);
            if(next_substring != hs.get_hash(0, diff)) {
                same = false;
                // printf("deu diferente aqui \n");
                break;
            }
            i += k;
        }
        if(same){
            cout << k << " ";
        }
        
    }
    return 0;
}