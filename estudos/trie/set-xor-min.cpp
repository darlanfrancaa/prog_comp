#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://judge.yosupo.jp/problem/set_xor_min

struct Vertex{
    int next[2];
    int qntd; 

    Vertex(){
        fill(begin(next), end(next), -1);
        qntd = 0;
    }
};

vector<Vertex> trie(1);

void add_num(int num){
    int v = 0; 
    for(int i=29;i>=0; i--){
        int b = (num >> i) & 1;
        if(trie[v].next[b] == -1){
            trie[v].next[b] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[b];
        trie[v].qntd++;
    }
}

void remove(int num){
    int v = 0; 
    for(int i=29;i>=0;i--){
        int b = (num >> i) & 1;
        v = trie[v].next[b];
        trie[v].qntd--;
    }
}

bool in(int num){
    int v = 0; 
    for(int i=29;i>=0;i--){
        int b = (num >> i) & 1;
        if(trie[v].next[b] == -1 || trie[trie[v].next[b]].qntd == 0) return false;
        v = trie[v].next[b];
    }
    return true;
}

int get_min_xor(int num){
    int v = 0; 
    int ans = 0;
    for(int i = 29; i>=0;i--){
        int b = (num >> i) & 1;
        if(trie[v].next[b] != -1 && trie[trie[v].next[b]].qntd > 0){
            v = trie[v].next[b]; 
            // a resposta não acrescenta em nada pois o bit existe e o xor seria 0
        } else { 
            v = trie[v].next[1-b];
            ans |= (1 << i);
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q; 
    while(q--){
        int tipo, v; cin >> tipo >> v; 
        if(tipo == 0){
            if(!in(v)){
                add_num(v);
            }
        } else if (tipo == 1){
            if(in(v)){
                remove(v);
            }
        } else { 
            cout << get_min_xor(v) << endl;
        }
    }
    return 0;
}