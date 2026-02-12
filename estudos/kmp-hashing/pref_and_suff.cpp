#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10; 
// problem link: https://codeforces.com/problemset/problem/432/D

int dp[N], ans[N];

vector<int> kmp(string s){
    int n = s.size(); 
    vector<int> pi(n);
    for(int i=1;i<n;i++){
        int j = pi[i-1];
        // printf("estou calculando agora para o índice %lld e o valor de j é %lld\n", i, j);
        while(j > 0 && s[i] != s[j]){
            // printf("estou dentro do while e analisei se s[%lld] = s[%lld], como não deu certo, j = pi[%lld] = %lld\n", i,j,j-1,pi[j-1]);
            j = pi[j-1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
        // printf("o valor de pi[%lld] = %lld\n", i, j);
    }
    return pi;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; 
    cin >> s; 
    int n = s.size(); 
    vector<int> pi; 
    pi = kmp(s);
    vector<int> ans(n+1);
    for(int i=0;i<n;i++){
        ans[pi[i]]++;
    }
    for(int i=n;i>=1;i--){
        ans[pi[i-1]] += ans[i];
        // printf("eu acrescentei no valor de pi[i-1] = pi[%lld] = %lld o valor de ans[%lld] = %lld\n", i-1, pi[i-1], i, ans[i]);
    }
    for(int i=0;i<=n;i++){
        ans[i]++;
    }
    // printf("acrescentei um no valor de todo mundo\n");
    int j = n;
    vector<int> sol;
    // printf("vou colocar todos os índices tais pref[i] = siff[j], comecando em j = %lld\n", n-1);
    stack<int> pilha;
    while(j >= 1){
        pilha.push(j);
        // printf("fiz o valor de j = %lld ir para o final de sol e fui para o próximo, fazendo j = pi[j-1] = %lld\n", j, pi[j-1]);
        // cout << j << ' ' << ans[j] << ' ';

        j = pi[j-1];
    }
    cout << pilha.size() << "\n";
    while(!pilha.empty()){
        int num = pilha.top(); pilha.pop(); 
        cout << num << ' ' << ans[num] <<  '\n';
    }
    return 0;
}