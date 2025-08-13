#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    for(int i=1;i<=n/2;i++){
        for(int j=1;j<=i;j++){
            cout << j << " ";
        }
        for(int j=i+1;j<=n-i;j++){
            cout << i << " ";
        }
        for(int j=n-i+1; j<=n;j++){
            cout << n-j+1 << " ";
        }
        cout << endl;
    }
    if(n%2 == 1) { 
        int i = (n+1)/2;
        for(int j=1;j<=i;j++){
            cout << j << " ";
        }
        for(int j=n-i+2; j<=n;j++){
            cout << n-j+1 << " ";
        }
        cout << endl;
    }
     for(int i=n/2;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout << j << " ";
        }
        for(int j=i+1;j<=n-i;j++){
            cout << i << " ";
        }
        for(int j=n-i+1; j<=n;j++){
            cout << n-j+1 << " ";
        }
        cout << endl;
    }


    return 0;
}