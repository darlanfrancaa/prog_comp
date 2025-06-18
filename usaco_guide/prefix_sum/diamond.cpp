#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k; 
    vector<int> diamonds(n);
    for(auto &diamond : diamonds) cin >> diamond; 
    sort(diamonds.begin(),diamonds.end());
    vector<int> prefix(n);

    int left = 0, right = 0;
    while(left < n){
        while(right < n && diamonds[right]-diamonds[left] <= k) right++;
        prefix[left] = right - left;
        left++;
    }

    vector<int> after(n+1);
    after[n] = 0;
    for(int i = n-1; i >= 0; i--){
        after[i] = max(after[i+1],prefix[i]);
    }
    //aqui estamos armazenando, para cada indice, o indice tal que o subarray que comeca nele
    //tenha o maior numero de elementos

    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans, prefix[i]+ after[i+prefix[i]]);
    }
    cout << ans;

    return 0;
}