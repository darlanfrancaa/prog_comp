#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;

// problem link: https://codeforces.com/gym/102861

const int MOD = 1e9+7; 
const int BASE = 911382323;
const int MAXM = 1e6+1;

int pot[MAXM]; 
void precalc(){
    pot[0] = 1; 
    for(int i=1;i<MAXM;i++){
        pot[i] = (pot[i-1] * BASE) % MOD;
    }
}

struct Hash{
    vector<int> h; 

    Hash(const string &s){
        int n = s.size(); 
        h.assign(n+1,0);
        for(int i=0;i<n;i++){
            h[i+1] = ((h[i] * BASE) % MOD + s[i]) % MOD;
        }
    }

    int get(int l, int r){
        int val = (h[r+1] - (h[l] * pot[r-l+1] % MOD) + MOD) % MOD;
        return val; 
    }    
};

struct Vertex{
    int next[26];
    int output; // vai salvar o id do time já que todos são distintos
    Vertex(){
        fill(begin(next), end(next), -1);
        output = -1;
    }
}; 

void insert_trie(vector<Vertex> &trie, const string &s, int id){
    int v = 0; 
    for(auto ch: s){
        int c = ch - 'a';
        if(trie[v].next[c] == -1){
            trie[v].next[c] = trie.size(); 
            trie.emplace_back();
        } 
        v = trie[v].next[c];
    }
    trie[v].output = id;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    precalc();
    int m,n; cin >> m >> n; 
    vector<string> a(m), b(n);
    vector<Vertex> trie_a(1);
    vector<Vertex> trie_b(1);

    for(int i=0;i<m;i++){
        cin >> a[i];
        insert_trie(trie_a,a[i], i);
    }

    for(int i=0;i<n;i++){
        cin >> b[i];
        string rev_b = b[i];
        reverse(rev_b.begin(), rev_b.end());
        insert_trie(trie_b,rev_b,i);
    }

    map<pii, vector<int>> mapa_a;
    map<pii, vector<int>> mapa_b;

    for(int i=0;i<m;i++){
        int v = 0;
        int len = a[i].size();
        Hash hash(a[i]);

        for(int j=0; j<len-1;j++){
            int c = a[i][j] - 'a';
            v = trie_a[v].next[c];
            if(v == -1) break;
            if(trie_a[v].output != -1){
                int s_len = len -1 - j; 
                int diff = hash.get(j+1,len-1);
                mapa_a[{diff, s_len}].push_back(i); 
                mapa_a[{diff, s_len}].push_back(trie_a[v].output); 
            }
        }
    }

    for(int i=0; i<n; i++){
        string rev_b = b[i];
        reverse(rev_b.begin(), rev_b.end());
        
        int v = 0;
        int len = b[i].size();
        Hash hash_b(b[i]); 
        
        for(int j=0; j<len-1; j++){
            int c = rev_b[j] - 'a';
            v = trie_b[v].next[c];
            if(v == -1) break;
            
            if(trie_b[v].output != -1){
                int s_len = len - 1 - j;
                int diff_hash = hash_b.get(0, s_len - 1); 
                
                mapa_b[{diff_hash, s_len}].push_back(i); 
                mapa_b[{diff_hash, s_len}].push_back(trie_b[v].output); 
            }
        }
    }

    vector<bool> npec_a(m,false);
    vector<bool> npec_b(n,false);

    for(auto const &[chave, valor]: mapa_a){
        if(mapa_b.count(chave)){
            for(int id: valor) npec_a[id] = true; 
            for(int id: mapa_b[chave]) npec_b[id] = true; 
        }
    }

    int ans_a = 0, ans_b = 0; 
    for(int i=0;i<m;i++) if(!npec_a[i]) ans_a++;
    for(int i=0;i<n;i++) if(!npec_b[i]) ans_b++;
    cout << ans_a << " " << ans_b << "\n";
    return 0;
}