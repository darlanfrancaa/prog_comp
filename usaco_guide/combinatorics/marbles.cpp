#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll binomial(int n, int k){
    if(k > n-k) k = n-k;
    ll ans = 1;
    for(int i=0;i<k;i++){
        ans = ans * (n-i)/(i+1);
    }
    return ans;
}

int main() {
    int n; cin >> n; 
    while(n--){
        int a, b; cin >> a >> b; 
        cout << binomial(a-1,b-1) << endl;
    }
    cout << endl;
}