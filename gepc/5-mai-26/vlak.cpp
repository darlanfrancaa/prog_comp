#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://oj.uz/problem/view/COCI20_vlak

struct Vertex{
    int next[26]; 
    bool has_nina = false; 
    bool has_emi = false;

    Vertex(){
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);

void add_string(string const& s, int p){
    int v = 0; 
    for(auto ch: s){
        int c = ch - 'a';
        if(trie[v].next[c] == -1){
            trie[v].next[c] = trie.size(); 
            trie.emplace_back();
        }
        v = trie[v].next[c];
        if(p == 1) trie[v].has_nina = true;
        else trie[v].has_emi  = true;
    }
}

int dfs(int v, int p){
    for(int i=0;i<26;i++){
        int u = trie[v].next[i];
        if(u != -1){
            bool valid = false; 
            if(p==1) valid = trie[u].has_nina;
            else valid = trie[u].has_emi;
            if(valid){
                if(!dfs(u, 3-p)){
                    return true;
                }
            }
        }
    }
    return false;
    
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    for(int i=0;i<n;i++){
        string s; cin >> s; 
        add_string(s, 1);
    }
    int m; cin >> m; 
    for(int i=0;i<m;i++){
        string s; cin >> s; 
        add_string(s,2);
    }
    cout << (dfs(0, 1) ? "Nina\n" : "Emilija\n");
    return 0;
}