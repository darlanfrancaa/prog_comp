#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k; 
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int>  vetor(2*n+1);
    for(int i=1;i<=n;i++){
        vetor[i] = a[i] - k*i;
    }
    for(int i=n+1; i<=2*n;i++){
        vetor[i] = a[i-n] - k*i;
    }
    int i=1;
    stack<int> p;
    p.push(1);
    vector<int> ans(2*n+1);
    while(i<= 2*n){
        while(!p.empty() && vetor[i] < vetor[p.top()]){
            ans[p.top()] = i;
            p.pop();
        }
        p.push(i);
        i++;
    }

    for(int i=1;i<=n;i++){
        if(ans[i] > n) cout << ans[i] - n << " "; 
        else cout << ans[i] << " ";
    }

    return 0;
}