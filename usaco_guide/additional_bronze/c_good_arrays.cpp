#include <bits/stdc++.h>
using namespace std;

//link : https://codeforces.com/contest/1398/problem/C

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t>0){
        t--;
        int n; cin >> n; 
        vector<int> vetor(n,0);
        for(int i=0;i<n;i++){
            char x; cin >> x;
            vetor[i] = x - '0' - 1;
        }
        map<int,int> mapa;
        mapa[0] = 1;
        long long ans = 0, acc = 0;
        for(int i=0;i<n;i++){
            acc += vetor[i];
            ans += mapa[acc];
            mapa[acc]++;
        }
        cout << ans << endl;
    }
    return 0;
}