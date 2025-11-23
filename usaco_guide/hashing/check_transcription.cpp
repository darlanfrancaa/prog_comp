#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

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

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    string s, t; cin >> t >> s; 
    int n0 = 0,n1 = 0;

    // Quero que sempre comece em 0, então se começar em 1 irei trocar tudo
    if(t[0] == '1'){
        for(int i=0;i<t.size();i++){
            if(t[i] == '1') t[i] = '0';
            else t[i] = '1';
        }
    }

    for(int i=0;i<t.size();i++){
        if(t[i] == '1') n1++;
        else n0++;
    }
    HashedString hs(s);
    // cout << "passou\n";
    int contador = 0;
    for(int s0=1;s0 * n0 <s.size();s0++){
        // aqui eu vou iterar pelos possíveis tamanhos de uma string;
        // eu tenho a formula de que n0.s0 + n1.s1 = s.size()
        int s1;
        int restante = s.size() - s0 * n0;
        if (n1 == 0) {
            if (restante != 0) continue; 
            s1 = 0; 
        } else {
            if (restante % n1 != 0) continue;
            s1 = restante / n1;
        }

        if(s1 < 1 && n1 > 0) continue;
        
        int inicial_hash_s0 = hs.get_hash(0, s0 - 1); // consegui o hash de s0,agora eu vou tentar descobrir o s1;
        int inicial_hash_s1;
        int t_pointer = 1, s_pointer = s0; // aqui serão os ponteiros que eu vou iterar por t e s

        bool valid = true;
        bool primeiro_um = true;

        while(t_pointer < t.size()){
            if(t[t_pointer] == '0'){
                // cout << "deu certo pra esse 0\n";
                if(s_pointer + s0 <= s.size() && hs.get_hash(s_pointer, s_pointer + s0 - 1) == inicial_hash_s0){
                    t_pointer++;
                    s_pointer = s_pointer + s0;
                } else {
                    valid = false; // isso quer dizer que essa substring não satisfez
                    break;
                }
            } else {
                if(primeiro_um){
                    // printf("spointer esta em %lld\n", s_pointer);
                    inicial_hash_s1 = hs.get_hash(s_pointer, s_pointer + s1 - 1);
                    // printf("hash0 %lld e hash1 %lld\n", inicial_hash_s0, inicial_hash_s1);
                    if(s0 == s1 && inicial_hash_s0 == inicial_hash_s1){
                        valid = false; 
                        break;
                    }
                    s_pointer = s_pointer + s1;
                    t_pointer++;
                    primeiro_um = false;
                } else {
                    // cout << "deu certo pra esse 1\n";
                    if(s_pointer + s1 <= s.size() && hs.get_hash(s_pointer, s_pointer + s1 - 1) == inicial_hash_s1){
                        t_pointer++;
                        s_pointer = s_pointer + s1;
                    } else {
                        valid = false;
                        break;
                    }
                }
            }
        
        }

        if(valid) contador++;
    }
    cout << contador << "\n";
    return 0;
}