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
        vector<int> beleza(n);
        for(auto &c: beleza) cin >> c;
        vector<int> pref_max(n);
        vector<int> suff_max(n);
        for(int i=0;i<n;i++){
            pref_max[i] = beleza[i] + i;
            suff_max[i] = beleza[i] - i;
        }
        for(int i=1;i<n;i++){
            pref_max[i] = max(pref_max[i], pref_max[i-1]);
        }
        for(int i=2;i<=n;i++){
            suff_max[n-i] = max(suff_max[n-i],suff_max[n-i+1]);
        }
        int maximo = 0;
        for(int i=1;i<n-1;i++){
            maximo = max(maximo, beleza[i] + pref_max[i-1] + suff_max[i+1]);
        }
        cout << maximo << endl;
    }
    return 0;
}