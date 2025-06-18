#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,x; cin >> n >> x; 
    vector<pair<int,int>> nums;
    for(int i=0;i<n;i++){
        int k; cin >> k;
        nums.push_back({k,i+1});
    }
    sort(nums.begin(),nums.end());
    int left = 0, right = n-1; 
    while(left < right){
        if(nums[left].first + nums[right].first > x) right--;
        else if(nums[left].first + nums[right].first < x) left++;
        else if(nums[left].first + nums[right].first == x) {
            cout << nums[left].second << " " << nums[right].second;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}