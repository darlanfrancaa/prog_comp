#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://judge.yosupo.jp/problem/set_xor_min

struct Vertex{
    int next[2]; 
    int qntd = 0;

    Vertex(){
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);

void add_num(int x){
    int v = 0; 
    trie[v].qntd++;
    for(int i=29;i>=0;i--){
        int bit = (x >> i) & 1;
        if(trie[v].next[bit] == -1){
            trie[v].next[bit] = trie.size(); 
            trie.emplace_back();
        }
        v = trie[v].next[bit];
        trie[v].qntd++;
    }
}

void remove_num(int x){
    int v = 0; 
    for(int i=29;i>= 0;i--){
        int bit = (x >> i) & 1;
        v = trie[v].next[bit];
        trie[v].qntd--;
    }
}

int find_min(int x){
    int acc = 0;
    int v = 0; 
    for(int i=29;i>=0;i--){
        int bit = (x >> i) & 1;
        int best_child = trie[v].next[bit];

        if(best_child != -1 && trie[best_child].qntd > 0) v = best_child;
        else {
            acc |= (1 << i);
            v = trie[v].next[bit^1];
        }
    }
    return acc;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    set<int> s; 

    int q; cin >> q;
    while(q--){
        int op, x; cin >> op >> x; 
        if(op == 0){
            if(s.find(x) == s.end()){
                s.insert(x);
                add_num(x);
            }
        } else if(op == 1){
            if(s.find(x) != s.end()){
                s.erase(x); 
                remove_num(x);
            }
        } else {
            cout << find_min(x) << endl;
        }
    }
    return 0;
}