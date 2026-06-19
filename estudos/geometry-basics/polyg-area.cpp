#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/2191

struct Point{
    int x; 
    int y; 
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<Point> p(n);
    for(int i=0;i<n;i++){
        cin >> p[i].x >> p[i].y;
    }
    int area = 0;
    for(int i=0;i<n;i++){
        area += p[i % n].x * p[(i+1)%n].y;
    }
    for(int i=0;i<n;i++){
        area -= p[i%n].y * p[(i+1)%n].x;
    }
    cout << abs(area) << "\n";
    return 0;
}