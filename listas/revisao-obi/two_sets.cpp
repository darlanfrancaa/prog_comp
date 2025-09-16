#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link : https://cses.fi/problemset/result/14561800/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >>n;
    int num = n * (n+1) / 2; 
    if(num % 2 == 1) { 
        cout << "NO";
    } else { 
        num = num/2; 
        set<int> grupo1; 
        cout << "YES" << endl;
        int contador = 0;
        for(int i=n;i>=1;i--){
            if(num >= i){
                grupo1.insert(i);
                num -= i;
                contador++;
            }
        }
        cout << contador << "\n";
        for(int i = 1;i<=n;i++){
            if(grupo1.count(i)) cout << i << " ";
        }
        cout << "\n" << n - contador << "\n";
        for(int i=1;i<=n;i++){
            if(!grupo1.count(i)) cout << i << " ";
        }
        cout << "\n";

    }
    return 0;
}