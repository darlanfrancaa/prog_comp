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
        vector<int> nums(n,0);
        for(auto &num : nums) cin >> num;
        vector<int> ans(n,0);
        int maximo = INT_MIN;
        int maximo_contador = 0;
        for(int i=0;i<n;i++){
            if(nums[i] >= maximo) {
                maximo = nums[i];
                continue;
            } else {
                int diff = maximo - nums[i];
                int contador = 0; 
                while(diff > 0){
                    diff = diff >> 1;
                    contador++;
                }
                maximo_contador = max(maximo_contador, contador);
            }
        }
        cout << maximo_contador << endl;
    }
    return 0;
}