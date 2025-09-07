#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link: https://atcoder.jp/contests/abc141/tasks/abc141_d

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    priority_queue<int> pq; 
    for(int i=0;i<n;i++){
        int a; cin >> a; 
        pq.push(a);
    }
    while(m--){
        int a = pq.top(); pq.pop(); 
        a /= 2;
        pq.push(a);
    }
    int soma = 0;
    while(!pq.empty()){
        int a = pq.top(); pq.pop(); 
        soma += a;
    }
    cout << soma << "\n";
    return 0;
}