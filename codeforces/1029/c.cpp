#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t>0){
        t--;
        int n; cin >> n;
        int ans = 1;
        set<int> antigo, novo; 
        for(int i=0;i<n;i++){
            int num; cin >> num; 
            if(i==0){
                antigo.insert(num);
                continue;
            }
            novo.insert(num); 
            if(antigo.find(num) != antigo.end()){
                    antigo.erase(num);
            }
            if(antigo.empty()){ 
                ans++;
                antigo = novo;
            }
        }
        cout << ans << endl;
    }
    return 0;
}