#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<long long> prefix_sum(n+1);
    for(int i=1; i<=n; i++){
        ll x; cin >> x;
        prefix_sum[i] += prefix_sum[i-1] + x;
    }
    ll soma_maxima = prefix_sum[1];
    ll min_prefix = prefix_sum[0];
    for(int i=1; i<= n; i++){
        soma_maxima = max(soma_maxima, prefix_sum[i] - min_prefix);
        min_prefix = min(min_prefix, prefix_sum[i]);
    }
    cout << soma_maxima << endl;
    return 0;