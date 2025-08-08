#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
        int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if(n % 2  == 1) {
            cout << "Alice" << endl;
            continue;
        }
        else{
            if(n % 4==0){
                cout << "Bob" << endl;
            } else{ 
                cout << "Alice" << endl;
            }
        }
    }
    return 0;
}