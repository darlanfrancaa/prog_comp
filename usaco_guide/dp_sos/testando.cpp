#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

void calc(int n){
    for(int mask = 0; mask < (1<<n); mask++){
        for(int submask = mask; submask != 0; submask = (submask - 1) & mask){
            int subset = submask ^ mask;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    return 0;
}