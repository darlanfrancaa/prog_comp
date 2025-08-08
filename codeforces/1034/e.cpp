#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 2;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> qntd(MAXN+2, 0);
        for(int i=0;i<n;i++){
            int a; cin >> a; 
            qntd[a]++;
        }
        bool mex = false; 
        int first_mex = 0;
        for(int i=0; i<= MAXN;i++){
            if(!mex) { 
                if(qntd[i] == 0) {
                    mex = true; 
                    first_mex = i;
                } 
            }
        }
        vector<int> entradas(MAXN+2,0);
        for(int i=0;i<=first_mex;i++){
            int left = qntd[i];
            int right = n - i;
            if(left <= right) {
                entradas[left]++;
                entradas[right+1]--;
            }
        }
        int prefix = 0;
        for(int i=0;i<=n;i++){
            prefix += entradas[i];
            cout << prefix << " ";
        }
        cout << endl;
    }
    return 0;
}