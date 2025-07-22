#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
int dp[500001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, c; cin >> n >> c; 

    int contador = 0, maximo = 0;
    for(int i=0;i<n;i++){
        int a; cin >> a; 
        if(a == c) contador++;
        else dp[a] = max(dp[a],contador) + 1;
        maximo = max(maximo, dp[a]-contador);
    }
    cout << contador + maximo << endl; 
    
    return 0;
}