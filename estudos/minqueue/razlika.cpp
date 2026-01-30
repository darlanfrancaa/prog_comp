#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://dmoj.ca/problem/coci12c4p4


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k; 
    vector<int> v(n); 
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int tam = n-k; 
    sort(v.begin(),v.end());
    vector<int> diff;
    for(int i=0;i<n-1;i++){
        diff.push_back(v[i+1]-v[i]);
    }
    deque<int> q; // vai salvar os índices das diferenças
    int tam_deque = tam - 1; 
    int ans = LLONG_MAX; 

    for(int i=0;i<n-1;i++){
        if(!q.empty() && q.front() <= i - tam_deque) q.pop_front();
        while(!q.empty() && diff[q.back()] >= diff[i]) q.pop_back();
        q.push_back(i);
        if(i >= tam_deque - 1){
            int fim = i+1; 
            int comeco = i+1 - tam_deque;
            int M = v[fim] - v[comeco];
            int m = diff[q.front()];
            ans = min(ans, M+m);
        }
    }

    cout << ans << "\n";
       

    return 0;
}