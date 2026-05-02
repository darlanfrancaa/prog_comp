#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://www.spoj.com/problems/PHONELST/

struct Vertex{
    int next[10];
    bool output = false; 
    int qntd = 0;
    Vertex(){
        fill(begin(next), end(next), -1);
    }
};

bool add_string(vector<Vertex> &trie, string const &s){
    int v = 0; 
    for(auto ch: s){
        int c = ch - '0';
        if(trie[v].next[c] == -1){
            trie[v].next[c] = trie.size(); 
            trie.emplace_back();
        }
        int u = trie[v].next[c];
        if(trie[u].output) return true; // se alguém é prefixo dele retorna true
        trie[u].qntd += 1;
        v = u;
    }
    trie[v].output = true;
    // se terminou e o valor é >=2, então tem alguém pra baixo
    if(trie[v].qntd >= 2) return true; 
    return false;
}

void solve(){
    int n; cin >> n; 
    vector<Vertex> trie(1);
    bool tem_pref = false; 
    for(int i=0;i<n;i++){
        string s;
        cin >> s; 
        tem_pref = tem_pref | add_string(trie, s);
    }
    if(tem_pref){
        cout << "NO\n";
    } else cout << "YES\n";

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}