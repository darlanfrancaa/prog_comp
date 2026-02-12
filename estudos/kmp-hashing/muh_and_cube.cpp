#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int inf = -2e9;

// problem link: https://codeforces.com/problemset/problem/471/D

vector<int> kmp(vector<int> &s){
    int n=s.size(); 
    vector<int> pi(n);
    for(int i=1;i<n;i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]) j++; 
        pi[i] = j;
    }
    return pi;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m; 
    vector<int> v(n), v1(m);
    for(int i=0;i<n;i++) cin >> v[i];
    
    for(int i=0;i<m;i++) cin >> v1[i];
    if(m == 1){
        cout << n << '\n';
        return 0;
    }
    vector<int> diff, s;
    for(int i=1;i<n;i++) diff.push_back(v[i-1] - v[i]);
    for(int i=1;i<m;i++) s.push_back(v1[i-1] - v1[i]);
    vector<int> pi,  string_final = s; 
    string_final.push_back(inf);
    string_final.insert(string_final.end(), diff.begin(), diff.end());
    // for(auto val : string_final){
    //     cout << val << " "; 
    // }
    int ans = 0;
    pi = kmp(string_final);
    for(int i=m; i<m+n-1; i++){
        if(pi[i] == m-1) {
            ans++;
            // printf("estou na posição i = %lld e o pi[%lld] = m - 1 = %lld, portanto aqui tem uma aparição\n", i,i, m-1);
        }
    }
    cout << ans << '\n';

    return 0;
}