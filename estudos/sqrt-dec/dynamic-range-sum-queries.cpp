#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/1648
const int N = 200010;
const int B = 500;
int v[N], sum[N];

void update(int i, int x){
    sum[i/B] += x; 
    sum[i/B] -= v[i];
    v[i] = x;
    return;
}

int query(int l, int r){
    int ans = 0; 
    while(l <= r && l % B != 0){
        ans += v[l]; 
        l++;
    }
    while(l+B-1 <= r){
        ans += sum[l/B]; 
        l += B;
    }
    while(l <= r){
        ans += v[l]; 
        l++;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q; 
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum[i/B] += v[i];
    }
    while(q--){
        int t; cin >> t; 
        if(t == 1){
            int pos, val; cin >> pos >> val;
            pos--; 
            update(pos,val);
        } 
        else { 
            int l, r; 
            cin >> l >> r; 
            l--;r--;
            cout << query(l,r) << '\n';
        }
    }
    return 0;
}