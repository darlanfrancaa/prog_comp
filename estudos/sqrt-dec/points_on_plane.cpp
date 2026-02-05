#include <bits/stdc++.h>
using namespace std;

// define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://codeforces.com/contest/576/problem/C

const int MAXN = 1e6+10;
vector<int> ret[1010];
pii p[MAXN];
int idx(int x){
    return x/1000;
}

bool cmp_even(int a, int b){
    return p[a].second < p[b].second;
}

bool cmp_odd(int a, int b){
    return p[a].second > p[b].second;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    for(int i=0;i<n;i++){
        int a, b; cin >> a >> b; 
        p[i] = {a,b};
        ret[idx(a)].push_back(i);
    }
    for(int i=0;i<=1000;i++){
        if(ret[i].empty()) continue;
        if(i % 2 == 0) sort(ret[i].begin(), ret[i].end(), cmp_even);
        else sort(ret[i].begin(), ret[i].end(), cmp_odd);
    }

    for(int i=0;i<=1000;i++){
        for(auto c: ret[i]) cout << c + 1 << ' ';
    }


    return 0;
}