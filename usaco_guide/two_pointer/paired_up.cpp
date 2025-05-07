#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    map<int,int> cows;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int qntd,num; cin >> qntd >> num; 
        nums.push_back(num);
        cows[num] = qntd;
    }
    sort(nums.begin(),nums.end());
    int left = 0, right = n - 1;
    int max_sum = 0;
    while(left <= right){
        max_sum = max(max_sum, nums[left]+nums[right]);
        if(cows[nums[left]] < cows[nums[right]]) cows[nums[right]] -= cows[nums[left++]];
        else if(cows[nums[left]] > cows[nums[right]]) cows[nums[left]] -= cows[nums[right--]];
        else if(cows[nums[left]] == cows[nums[right]]) {
            left++; right --;
        }
    } 
    cout << max_sum;
    return 0;
}