#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        deque<char> pal; 
        char car;
        for(int i=0;i<n;i++) {
            cin >> car; 
            pal.push_back(car);
        }
        int k; cin >> k; 
        string pal1, pal2; 
        cin >> pal1 >> pal2; 
        for(int i=0;i<k;i++){
            if(pal2[i] == 'D') pal.push_back(pal1[i]);
            else if(pal2[i] == 'V') pal.push_front(pal1[i]);
        }
        for(auto c: pal) cout << c;
        cout << endl;
    }
    return 0;
}