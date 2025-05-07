#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x; cin >> n >> x; 
    vector<int> nums(n);
    for(auto &num: nums) cin >> num;
    int left = 0, right = 0, ans = 0;
    ll sum = 0;
    while(left<n && right <n){
        sum += nums[right++];
        while(sum > x && left < right) sum -= nums[left++];
        if(sum == x) ans ++;
    }
    cout << ans;
    return 0;
}