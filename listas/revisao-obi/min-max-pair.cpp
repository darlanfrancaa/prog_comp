#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link : https://atcoder.jp/contests/abc262/tasks/abc262_c

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    int<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    int contador_pa = 0, fixos = 0;
    for(int i=1;i<=n;i++){
        if(v[i] == i) {
            fixos++; continue;
        } else if( v[i] < i) continue;
        else if( v[i] > i){
            int j = v[i];
            if(v[j] == i) contador_pa++;
        }
    }
    contador_pa += (fixos * (fixos - 1)) / 2;
    cout << contador_pa << "\n";
    return 0;
}