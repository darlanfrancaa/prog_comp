#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> towers;
    int first; cin >> first; 
    towers.push_back(first);
    for(int i=1;i<n;i++){
        int a; cin >> a; 
        int left = 0, right = towers.size();
        if(towers[right-1] <= a){
            towers.push_back(a);
        } else if(towers[0] > a){
            towers[0] = a;
        } else {
            while(right - left > 1){ 
                int mid = (left + right) / 2; 
                if(towers[mid] > a) right = mid; 
                else left = mid;
            }
            towers[right] = a;
        }
    }
    cout <<  towers.size();
    return 0;
}