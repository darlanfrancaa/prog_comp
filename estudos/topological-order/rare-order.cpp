#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
// problem link: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=136
const int N = 30;
vector<int> adj[N];
vector<int> cor;
bool has_cycle;
vector<int> ans;
void dfs(int v){
    cor[v] = 1; 
    for(auto u: adj[v]){
        if(cor[u] == 0) dfs(u);
        else if(cor[u] == 1) has_cycle = true;
    }
    cor[v] = 2; 
    ans.push_back(v);
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<string> v;
    
    while(true){
        string s; cin >> s; 
        if(s == "#") break;
        v.push_back(s);
    }
    int n = v.size();
    set<int> letras;
    for(int i = 0; i < n; i++){
        for(char c : v[i]){
            letras.insert(c - 'A');
        }
    }

    for(int i=0;i<n-1;i++){
        string s1 = v[i];
        string s2 = v[i+1];
        int k=0;
        while(k < s1.size() && k < s2.size() && s1[k] == s2[k]){
            k++;
        } 
        if(k == s1.size() || k == s2.size()) continue;
        int letra1 = s1[k] - 'A', letra2 = s2[k] - 'A';
        letras.insert(letra1); letras.insert(letra2);
        adj[letra1].push_back(letra2);
    }

    cor.assign(N, 0);
    ans.clear();
    for(int i = 0; i < 26; i++){
        if(letras.count(i) && cor[i] == 0){
            dfs(i);
        }
    }
    
    reverse(ans.begin(), ans.end());
    string resp = "";
    for(auto val : ans){
        resp.push_back('A' + val);
    }
    
    cout << resp << "\n";
    
    return 0;
}