#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://open.kattis.com/problems/segmentintersection



struct Point{
    int x; 
    int y;
};

struct PointDouble {
    double x, y;
    bool operator<(const PointDouble& o) const {
        if (abs(x - o.x) > 1e-9) return x < o.x;
        return y < o.y;
    }
    bool operator==(const PointDouble& o) const {
        return abs(x - o.x) <= 1e-9 && abs(y - o.y) <= 1e-9;
    }
};

PointDouble intersect_lines(Point p1, Point p2, Point p3, Point p4) {
    double a1 = p2.y - p1.y;
    double b1 = p1.x - p2.x;
    double c1 = a1 * p1.x + b1 * p1.y;

    double a2 = p4.y - p3.y;
    double b2 = p3.x - p4.x;
    double c2 = a2 * p3.x + b2 * p3.y;

    double det = a1 * b2 - a2 * b1;
    return { (b2 * c1 - b1 * c2) / det, (a1 * c2 - a2 * c1) / det };
}


int pos(Point &p1, Point &p2, Point &p3){
    Point a = {p2.x - p1.x, p2.y - p1.y};
    Point b = {p3.x - p1.x, p3.y - p1.y};
    int val = a.x*b.y - a.y*b.x;
    if(val < 0) return -1;
    else if (val == 0) return 0;
    else return 1;
}

bool dentro(Point p, Point a, Point b) {
    return p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
           p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y);
}

void solve(){
    Point p1,p2,p3,p4; 
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y; 
    int o1 = pos(p1, p2, p3);
    int o2 = pos(p1, p2, p4);
    int o3 = pos(p3, p4, p1);
    int o4 = pos(p3, p4, p2);

    if (o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0) {
        vector<PointDouble> validos;
        if (dentro(p3, p1, p2)) validos.push_back({(double)p3.x, (double)p3.y});
        if (dentro(p4, p1, p2)) validos.push_back({(double)p4.x, (double)p4.y});
        if (dentro(p1, p3, p4)) validos.push_back({(double)p1.x, (double)p1.y});
        if (dentro(p2, p3, p4)) validos.push_back({(double)p2.x, (double)p2.y});

        if (validos.empty()) {
            cout << "none\n";
            return;
        }

        sort(validos.begin(), validos.end());
        validos.erase(unique(validos.begin(), validos.end()), validos.end());

        cout << fixed << setprecision(2);
        if (validos.size() == 1) {
            cout << validos[0].x << " " << validos[0].y << "\n";
        } else {
            cout << validos.front().x << " " << validos.front().y << " " << validos.back().x << " " << validos.back().y << "\n";
        }
        return;
    }

    bool intersecta = false;
    if (o1 != o2 && o3 != o4) intersecta = true;
    if (o1 == 0 && dentro(p3, p1, p2)) intersecta = true;
    if (o2 == 0 && dentro(p4, p1, p2)) intersecta = true;
    if (o3 == 0 && dentro(p1, p3, p4)) intersecta = true;
    if (o4 == 0 && dentro(p2, p3, p4)) intersecta = true;

    if (!intersecta) {
        cout << "none\n";
        return;
    }

    PointDouble pt = intersect_lines(p1, p2, p3, p4);
    if (abs(pt.x) < 1e-9) pt.x = 0.0;
    if (abs(pt.y) < 1e-9) pt.y = 0.0;

    cout << fixed << setprecision(2) << pt.x << " " << pt.y << "\n";

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}