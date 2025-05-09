#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int n, k; 
vector<int> cows;

bool its_possible(int power){
    int left  = 0, right = 0, contador = 0 ;
    while(right < n){
        if (left == right) contador++;
        if (cows[right]-cows[left] > 2*power) left = right;
        else right++;
    }
    return contador <= k;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    cows.resize(n);
    for(auto &cow: cows) cin >> cow;
    sort(cows.begin(),cows.end());
    int left = 0, right  = 1e9;
    while(left < right){
        int mid = left + (right - left)/2;
        if (its_possible(mid)) right = mid; 
        else left = mid + 1; 
    }
    cout << left << endl;
    return 0;
}