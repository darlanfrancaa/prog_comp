#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        string num; cin >> num;
        int min_d = INT_MAX;
        for(auto dig: num){
            int atual = dig - '0';
            min_d = min(min_d,atual);
        }
        cout << min_d << endl;
    }
    return 0;
}