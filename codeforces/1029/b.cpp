#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

void sequencia(int n){
    if(n%2 == 1){
        for(int i=1;i<=n;i+=2){
            cout << i << " ";
        }
        for(int i=n-1;i>=2;i-=2){
            cout << i << " ";
        }
    }
    else {
        for(int i=1;i<n;i+=2){
            cout << i << " ";
        }
        for(int i=n;i>=2;i-=2){
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t>0){
        t--;
        int n; cin >> n;
        sequencia(n);
    }
    return 0;
}