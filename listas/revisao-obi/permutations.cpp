#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

//link : https://cses.fi/problemset/task/1070

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    if(n == 3 || n == 2) { 
        cout << "NO SOLUTION" << "\n";
        return 0;
    } if( n == 4){
        cout << 2 << " " << 4 << " " << 1 << " " << 3;
        return 0;
    }
    if (n% 2 == 1){
        int<int> v(n+1);
        int m = (n+1)/2; 
        v[m] = n;
        int left = m-1, right = m+1;
        int contador = 0;
        while(left - contador >= 1 && right + contador <= n){
            v[left-contador] = (contador * 2) + 1;
            v[right+contador] = (contador * 2) + 2;
            contador++;
        } 
        for(int i=1;i<=n;i++){
            cout << v[i] << " ";
        }
    } else if( n%2 == 0){
        int m = n/2;
        int i = 1;
        int<int> v(n+1);
        while(i <= m){
            v[i] = 2*i - 1;
            v[i+m] = 2*i ;
            i++;
        }
        for(int i=1;i<=n;i++){
            cout << v[i] << " ";
        }
    }

    return 0;
}