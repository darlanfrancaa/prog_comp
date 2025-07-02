#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

/*problem link: https://codeforces.com/contest/1368/problem/D*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> nums(n);
    for(auto &num:nums) cin >> num;
    vector<int> bits(20);
    for(int i=0;i<20;i++){
        for(int j=0;j<n;j++){
            if(nums[j] & (1ll << i)) bits[i]++;
        }
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        long long atual = 0;
        for(int j=0;j<20;j++){
            if(bits[j]){
                atual |= (1ll << j);
                bits[j]--;
            }
        }
        ans += atual * atual;
    }
    cout << ans << endl;
    return 0;
}