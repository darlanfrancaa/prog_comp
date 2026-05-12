#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/gym/105394/problem/M

int find_med(vector<int> &v){
    int n = v.size();
    if(v.size() % 2 == 1){
        return v[(n-1)/2];
    } else { 
        return (v[n/2 -1] + v[n/2]) / 2;
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<int> c(n);
    for(int i=0;i<n;i++){
        int val; cin >> val; 
        c[i] = i - val;
    }
    // agora devemos encontrar a mediana de val
    sort(c.begin(), c.end());
    int val = find_med(c);
    // printf("o valor encontrado da mediana foi %lld\n", val);
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += abs(val - c[i]);
    }
    cout << ans << "\n";
    
    return 0;
}