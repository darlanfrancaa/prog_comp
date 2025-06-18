#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, t; cin >> n >> t; 
    vector<int> books(n);
    for(auto &book:books) cin >> book; 
    int maximo = 0;
    int sum = 0;
    int left = 0, right = 0;
    while(left<n && right < n){
        while(right < n){
            sum += books[right];
            right++;
            if(sum>t){
                sum -= books[--right];
                break;
            }
        }
        maximo = max(maximo,right-left);
        sum -= books[left];
        left++;
    }
    cout << maximo; 
    return 0;
}