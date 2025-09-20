#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k; 
    map<string,priority_queue<int>> mapa; 
    for(int i=0;i<n;i++){
        string s; int h; cin >> s >> h; 
        mapa[s].push(h);
    }
    int contador = 0;
    for(auto [s,pq]: mapa){
        int qntd = 0;
        while(!pq.empty() && qntd < k){
            int h = pq.top(); pq.pop(); 
            contador += h; 
            qntd++;
        }
    }
    cout << contador << "\n";
    return 0;
}