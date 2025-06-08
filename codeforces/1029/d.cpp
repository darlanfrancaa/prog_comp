#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int j; cin >> j; 
    while(j>0){
        j--;
        int n; cin >> n;
        vector<int> nums(n);
        for(auto &num:nums) cin >> num;
        bool ok = true;
        int op1, op2;
        int sum = nums[0] + nums[n-1];
        if (sum % (n+1) != 0) ok = false;
        else {
            int t = sum / (n+1);
            if((nums[0] - t) % (n-1) != 0) ok = false;
            else{
                op2 = (nums[0] - t) / (n-1);
            }
            if((nums[n-1] - t) % (n-1) != 0) ok = false;
            else{
                op1 = (nums[n-1] - t) / (n-1);
            }
            if(op1 < 0 || op2 < 0) ok = false;
        }
        for(int i=0;i<n;i++){
            if(nums[i] != op1 * (i+1) + op2 * (n-i)) ok = false;
        }
        if(ok == false) cout << "NO" << endl;
        else cout << "YES" << endl;

    }
    return 0;
}