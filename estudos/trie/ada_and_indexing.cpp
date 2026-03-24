#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://www.spoj.com/problems/ADAINDEX/

struct Vertex{
    int next[26];
    bool output = false;
    int qntd_out = 0; 
    Vertex(){
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);

void add_string(string &s){
    int v = 0; 
    for(char ch: s){
        int c = ch - 'a';
        if(trie[v].next[c] == -1){
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
        trie[v].qntd_out++;
    }
    trie[v].output = true;
}

int count_pref(string &s){
    int v = 0; 
    for(auto ch: s){
        int c = ch - 'a'; 
        if(trie[v].next[c] == -1) return 0;
        v = trie[v].next[c];
    }
    return trie[v].qntd_out;
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q; cin >> n >> q;
    for(int i=0;i<n;i++){
        string s; cin >> s; 
        add_string(s);
    }
    for(int i=0;i<q;i++){
        string s; cin >> s; 
        cout << count_pref(s) << endl;
    }
    
    return 0;
}