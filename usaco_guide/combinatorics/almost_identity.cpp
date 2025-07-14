#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

/*link: https://codeforces.com/problemset/problem/888/D*/

int per_caot[5] = {1,0,1,2,9};

ll binomial(int n, int k){
    if(k > n-k) k = n-k;
    ll ans = 1;
    for(int i=0;i<k;i++){
        ans = ans * (n-i)/(i+1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >> n >> k;
    ll ans = 0;
    for(int i=k;i>=0;i--){
        ans += binomial(n,i) * per_caot[i];
    }
    cout << ans << endl;
    return 0;
}