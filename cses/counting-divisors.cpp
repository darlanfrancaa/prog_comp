#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;

/*link do problema: https://cses.fi/problemset/task/1713*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> max_primo(MAXN,0);
    for(int i= 2; i<MAXN;i++){
        if(max_primo[i] == 0){
            for(int j=i;j<MAXN;j+=i) max_primo[j] = i;
        }
    }
    int t; cin >> t;
    while(t>0){
        t--;
        int n; cin >> n;
        int prod = 1;
        while(n > 1){
            int contador = 0;
            int primo = max_primo[n];
            while((n % primo) == 0){
                contador++;
                n = (n/primo);
            }
            prod *= (contador+1);
        }
        cout << prod << endl;
    }
    
    return 0;
}