#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> nums(n);
    for(auto &num:nums) cin >> num;
    set<int> conjunto;
    int maximo = INT_MIN;
    int left = 0, right = 0;
    conjunto.insert(nums[left]);
    while(left < n){
        while(right + 1 < n && !conjunto.count(nums[right+1])){
            right++;
            conjunto.insert(nums[right]);
            maximo = max(maximo, right - left + 1);
        }
        conjunto.erase(nums[left]);
        left++;
    }
    cout << maximo << endl; 
    return 0;
}