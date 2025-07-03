#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 60;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b){
    return (a * b) / gcd(a,b);
}

// int phi(int n){
//     int ans = n; 
//     for(int p=2;p*p<=n;p++){
//         if(n % p==0){
//             while(n%p == 0) n/=p;
//             ans -= ans/p;
//         }
//     }
//     if(n>1) ans -= ans/n;
//     return ans;
// }
vector<int> phi(MAXN);

void precompute(){
    for(int i=0;i<MAXN;i++) phi[i] = i;
    for(int i=2;i<MAXN;i++){
        if(phi[i]==i){
            for(int j=i;j<MAXN;j+=i) phi[j] -= phi[j]/i;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    precompute();
    for(auto num : phi) cout << num << " ";
    return 0;
}