#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://judge.yosupo.jp/problem/sort_points_by_argument

struct Point{
    int x; 
    int y;
    long double arg;
};

bool compare(Point &a, Point &b){
    return a.arg < b.arg;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<Point> points(n);
    for(int i=0;i<n;i++) {
        cin >> points[i].x >> points[i].y; 
        points[i].arg = atan2l(points[i].y, points[i].x);
    }
    sort(points.begin(), points.end(), compare);
    for(auto p: points){
        cout << p.x << " " << p.y << "\n";
    }

    return 0;
}