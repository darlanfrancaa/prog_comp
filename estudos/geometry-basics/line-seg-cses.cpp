#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/2190

struct Point{
    int x, y;
};

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
    
    if (o1 != o2 && o3 != o4) {
        cout << "YES\n";
        return;
    }

    if (o1 == 0 && dentro(p3, p1, p2)) { cout << "YES\n"; return; }
    if (o2 == 0 && dentro(p4, p1, p2)) { cout << "YES\n"; return; }
    if (o3 == 0 && dentro(p1, p3, p4)) { cout << "YES\n"; return; }
    if (o4 == 0 && dentro(p2, p3, p4)) { cout << "YES\n"; return; }
    
    else cout << "NO\n";
    return;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}