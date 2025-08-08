#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n,s; cin >> n >> s;
        if(n == 1){
            int a; cin >> a; 
            cout << abs(s-a) << endl;
            continue;
        }
        int menor = INT_MAX, maior = INT_MIN;
        for(int i=0;i<n;i++){
            int a; cin >> a; 
            menor = min(a,menor);
            maior = max(a,maior);
        }
        int ans = 0; 
        if(menor <= s && s <= maior){
            ans += (maior - menor);
            ans += min(maior-s, s-menor);
            cout << ans << endl;
        }
        else if(s <= menor){
            cout << maior - s << endl;
        }
        else if(s >= maior) {
            cout << s - menor << endl;
        }
    }
    return 0;
}