#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int,int>;
const int MOD = 1e9 + 7;
vector<pii> nums;

#define f first

pii two_pointers(vector<pii> &nums, int mid, int target){
    ll n = nums.size();
    int left = 0, right = n-1; 
    int meio = nums[mid].f;
    while(left<mid && right > mid){
        if(nums[left].f + meio + nums[right].f < target) left++;
        else if(nums[left].f + meio + nums[right].f > target) right--;
        else if(nums[left].f + meio + nums[right].f == target) return {nums[left].second,nums[right].second};
    }
    return {0,0};
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, target; cin >> n >> target; 
    for(int i=0;i<n;i++){
        int x; cin >> x; 
        nums.push_back({x,i+1});
    }
    sort(nums.begin(),nums.end());
    int mid = 1;
    while(mid<n-1){
        pii find = two_pointers(nums,mid,target);
        if(find.first!=0 and find.second!=0){
            cout << find.first << " " <<  nums[mid].second << " " << find.second;
            return 0;
        }
        else mid++;
    }
    cout << "IMPOSSIBLE";
}