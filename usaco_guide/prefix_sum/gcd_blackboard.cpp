#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> nums(n,0);
    vector<int> prefix_sum(n,0);
    vector<int> suffix_sum(n,0);
    for(auto &num: nums) cin >> num;
    prefix_sum[0] = nums[0];
    suffix_sum[n-1] = nums[n-1];
    for(int i=1;i<n;i++){
        prefix_sum[i] = gcd(prefix_sum[i-1],nums[i]);
    }
    for(int i=n-2;i>=0;i--){
        suffix_sum[i] = gcd(suffix_sum[i+1],nums[i]);
    }

    int maximo = max(prefix_sum[n-2],suffix_sum[1]);
    if (n==2){
        cout << max(nums[0],nums[1]);
    }else{
        for(int i=1;i<n-1;i++){
            maximo = max(maximo, gcd(prefix_sum[i-1],suffix_sum[i+1]));
        }
        cout << maximo;
    }
    
}