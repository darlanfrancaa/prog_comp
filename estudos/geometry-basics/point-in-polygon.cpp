#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/2192

struct Point {
    int x;
    int y; 
};

bool dentro(const Point &p1, const Point &p2, const Point &p){
    int xmin = min(p1.x, p2.x);
    int xmax = max(p1.x, p2.x);
    int ymin = min(p1.y, p2.y);
    int ymax = max(p1.y, p2.y);
    Point a = {p2.x - p1.x, p2.y - p1.y};
    Point b = {p.x - p1.x, p.y - p1.y};
    
    bool reta = (1LL * a.x * b.y - 1LL * a.y * b.x == 0);
    
    return reta && xmin <= p.x && p.x <= xmax && ymin <= p.y && p.y <= ymax; 
}

long long trigonometric_sense(Point p, Point p1, Point p2) {
    return 1LL * (p1.x - p.x) * (p2.y - p.y) - 1LL * (p2.x - p.x) * (p1.y - p.y);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; 
    if (!(cin >> n >> m)) return 0;

    vector<Point> poly(n);
    for(Point &p : poly) cin >> p.x >> p.y;
    
    for (int q = 0; q < m; q++) {
        Point p;
        cin >> p.x >> p.y;
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if (dentro(poly[i], poly[j], p)) {
                flag = true;
                break;
            }
            if (poly[i].y <= p.y && p.y < poly[j].y && trigonometric_sense(p, poly[i], poly[j]) > 0) cnt++;
            if (poly[j].y <= p.y && p.y < poly[i].y && trigonometric_sense(p, poly[j], poly[i]) > 0) cnt++;
        }
        
        if (flag) {
            cout << "BOUNDARY" << '\n';
        } else {
            cout << (cnt % 2 ? "INSIDE" : "OUTSIDE") << '\n';
        }
    }
    
    return 0;
}