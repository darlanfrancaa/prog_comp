#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        // entao eu preciso saber se um número é o mínimo de um prefixo
        // o maximo de um sufixo
        int n; cin >> n;
        vector<int> nums(n);
        for(auto &num:nums) cin >> num;
        if(n == 2) {
            cout << 11 << endl;
            continue;
        }
        vector<int> prefix(n), suffix(n);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i=1; i<n;i++){
            prefix[i] = min(prefix[i-1], nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suffix[i] = max(suffix[i+1],nums[i]);
        }
        for(int i = 0; i< n;i++){
            if(nums[i] == prefix[i] || nums[i] == suffix[i]){
                cout << 1;
            } else cout << 0;
        }
        cout << endl; 
    }
    return 0;
}