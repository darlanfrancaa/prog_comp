#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/gym/102861/problem/H
const int MAXN = 52;
int choose[MAXN][MAXN];
vector<int> box; 
int n,k;

void precompute(){
    for(int i=0;i<MAXN;i++){
        choose[i][0] = 1;
    }

    for(int i=1;i<MAXN;i++){
        for(int j=1;j<=i;j++){
            choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
        }
    }
}

int compute(int valor, int k, int max_idx){
    if(k == 0) return (valor >= 0) ? 1 : 0;
    if(valor < 0 || max_idx < 0) return 0;

    auto it = upper_bound(box.begin(), box.begin() + max_idx + 1, valor);

    if(it == box.begin()) return 0;
    --it;
    int i = it - box.begin();
    int ret = 0;
    if(i >= k) ret += choose[i][k];
    ret += compute(valor-box[i], k-1, i-1);
    return ret;
}

int solve(int valor, int k){
    return compute(valor, k, n-1);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    precompute(); 
    cin >> n >> k;
    box.resize(n);
    for(int i=0;i<n;i++){
        cin >> box[i];
    }
    sort(box.begin(), box.end());
    int a,b; cin >> a >> b;
    cout << solve(b,k) - solve(a-1,k);
    return 0;
}