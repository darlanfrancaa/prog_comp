#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://open.kattis.com/problems/segmentdistance

struct Point{
    int x; 
    int y; 
};

double dist_points(Point a, Point b) {
    return sqrt((double)(a.x - b.x)*(a.x - b.x) + (double)(a.y - b.y)*(a.y - b.y));
}

int cross(Point a, Point b, Point c) {
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

int dot(Point a, Point b, Point c) {
    return (b.x - a.x)*(c.x - a.x) + (b.y - a.y)*(c.y - a.y);
}

int pos(Point p1, Point p2, Point p3) {
    int val = cross(p1, p2, p3);
    if (val < 0) return -1;
    if (val > 0) return 1;
    return 0;
}

bool dentro(Point p, Point a, Point b) {
    return p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
           p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y);
}

bool intersect(Point p1, Point p2, Point p3, Point p4) {
    int o1 = pos(p1, p2, p3);
    int o2 = pos(p1, p2, p4);
    int o3 = pos(p3, p4, p1);
    int o4 = pos(p3, p4, p2);

    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && dentro(p3, p1, p2)) return true;
    if (o2 == 0 && dentro(p4, p1, p2)) return true;
    if (o3 == 0 && dentro(p1, p3, p4)) return true;
    if (o4 == 0 && dentro(p2, p3, p4)) return true;
    return false;
}

double dist_segment(Point p, Point a, Point b) {
    if (a.x == b.x && a.y == b.y) return dist_points(p, a);
    if (dot(a, b, p) <= 0) return dist_points(p, a);
    if (dot(b, a, p) <= 0) return dist_points(p, b);
    double area = abs((double)cross(a, b, p));
    double base = dist_points(a, b);
    return area / base;
}

void solve(){
    Point p1,p2,p3,p4; 
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y; 

    if (intersect(p1, p2, p3, p4)) {
        cout << fixed << setprecision(2) << 0.00 << "\n";
        return;
    }

    double ans = 1e18;
    ans = min(ans, dist_segment(p1, p3,p4)); 
    ans = min(ans, dist_segment(p2, p3,p4)); 
    ans = min(ans, dist_segment(p3, p1,p2)); 
    ans = min(ans, dist_segment(p4, p1,p2)); 
    cout << fixed << setprecision(2) << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}