#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n; cin >> n;
    int contador =0;
    for(long long p=2;p*p<=n;p++){
        int k = 0;
        while(n % p == 0){
            k++;
            n/=p;
        }
        for(int i=1; k-i >= 0;i++){
            k -= i;
            contador++;
        }
    }
    if(n>1) contador++;
    cout << contador << endl;

    
    return 0;
}