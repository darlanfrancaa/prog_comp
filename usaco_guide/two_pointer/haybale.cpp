#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> sum(n+2); 
    for(int i=0;i<k;i++){
        int a, b; cin >> a >> b; 
        sum[a]++;
        sum[b+1]--;
    }
    for(int i=1;i<=n;i++){
        sum[i] += sum[i-1];
    }
    sort(sum.begin()+1, sum.begin()+n+1);
    cout << sum[(n+1)/2];
    return 0;
}