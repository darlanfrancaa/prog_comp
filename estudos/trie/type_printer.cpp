#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int N = 25010;

struct Vertex{
    int next[26];
    bool output = false; 
    int dp1 = 0, dp2 = 0;
    int best_ch = -1;
    Vertex(){
        fill(begin(next), end(next), -1);
    }
};
string caminho = "";
vector<Vertex> trie(1);
int dp1[N], dp2[N];
void add(string &s){
    int v = 0; 
    for(auto ch: s){
        int c = ch - 'a';
        if(trie[v].next[c] == -1){
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].dp1++;
    trie[v].dp2++;
    trie[v].output = true;
}

void dfs(int node){
    int max_dif = 0;
    for(int i=0;i<26;i++){
        if(trie[node].next[i] != -1){
            int prox = trie[node].next[i];
            dfs(prox);
            trie[node].dp2 += trie[prox].dp2 + 2;
            trie[node].dp1 += trie[prox].dp2 + 2;
            int save = trie[prox].dp2 - trie[prox].dp1 +1;
            if(save > max_dif){
                max_dif = save;
                trie[node].best_ch = i;
            }
        }
    }
    trie[node].dp1 -= max_dif;
    // printf("No nó node = %lld temos que ans1 = %lld e ans2 = %lld\n", node, dp1[node], dp2[node]);
}

void build_caminho(int node){
    if(trie[node].output == true){
        caminho.push_back('P');
    }
    for(int i=0;i<26;i++){
        if(trie[node].next[i] != -1 && trie[node].best_ch != i){
            int prox = trie[node].next[i];
            caminho.push_back(i + 'a');
            build_caminho(prox);
            caminho.push_back('-');
        }
    }

    if(trie[node].best_ch != -1){
        int i = trie[node].best_ch;
        int prox =  trie[node].next[i];
        caminho.push_back(i + 'a');
        build_caminho(prox);
        caminho.push_back('-');
    }
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    while(n--){
        string s; 
        cin >> s; 
        add(s); 
    }
    dfs(0);
    build_caminho(0);
    cout << trie[0].dp1 << endl;
    while(!caminho.empty() && caminho.back() == '-') caminho.pop_back();
    for(int i=0;i<caminho.size();i++){
        cout << caminho[i] << "\n";
    }
    // cout << caminho.size();
    return 0;
}