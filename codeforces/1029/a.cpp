#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t>0){
        t--;
        int n, x; cin >> n >> x;
        int primeiro = -1, ultimo = -1; 
        for(int i=0;i<n;i++){
            int door; cin >> door;
            if (door == 1){
                if(primeiro == -1){
                    primeiro = i;
                    ultimo = i;
                } else {
                    ultimo = i;
                }
            }
        }
        int diff = ultimo - primeiro + 1;
        if(diff <= x) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}