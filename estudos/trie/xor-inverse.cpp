#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://gemini.google.com/app/f350f356367949d5

struct Vertex{
    int next[2];
    int output; 
    int qntd1 = 0, qntd0 = 0;
    Vertex(){
        fill(begin(next), end(next), -1);
        output = 0;
    }
};

vector<Vertex> trie(1);
int qntd_10[32], qntd_01[32];

void add(int num){
    int v = 0; 
    int nivel = 30;
    for(int i=30; i>=0;i--){
        int b = (num >> i) & 1;
        if(trie[v].next[b] == -1){
            trie[v].next[b] = trie.size();
            trie.emplace_back();
        }
        if(b == 1){
            qntd_01[nivel] += trie[v].qntd0;
            trie[v].qntd1++;
        } else { 
            qntd_10[nivel] += trie[v].qntd1; 
            trie[v].qntd0++;
        }
        nivel--;
        v = trie[v].next[b];
    }
    trie[v].output++;
}



signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    while(n--){
        int val; cin >> val; 
        add(val);
    }
    int ans = 0, ans_inv = 0; 
    for(int nivel = 30; nivel >= 0; nivel--){
        if(qntd_10[nivel] > qntd_01[nivel]){
            ans = ans | (1LL << nivel);
            ans_inv += qntd_01[nivel];
        } else { 
            ans_inv += qntd_10[nivel];
        }
    }
    cout << ans_inv << " " << ans << endl; 
    return 0;
}