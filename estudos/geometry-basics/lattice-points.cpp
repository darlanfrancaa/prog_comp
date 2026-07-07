#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

// problem link: https://cses.fi/problemset/task/2193

struct Point{
    int x; 
    int y; 
};

// Usaremos que lp = A - b/2 + 1, onde b é a quantidade de lattice points que estão na borda do polígono

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; 
    vector<Point> points(n);
    for(Point &p: points) cin >> p.x >> p.y;
    points.push_back(points[0]); // para ciclar

    int area = 0; 
    for(int i=0;i<n;i++){
        area += (1LL * points[i].x * points[i+1].y);
        area -= (1LL * points[i].y * points[i+1].x);
    }
    area = abs(area);
    int border_points = 0; 
    for(int i=0;i<n;i++){
        Point diff = {points[i+1].x-points[i].x, points[i+1].y - points[i].y};
        int qtd = gcd(abs(diff.x), abs(diff.y));
        border_points += qtd;
    }
    int ans =  (area - border_points)/2 + 1;
    cout << ans << " " << border_points << endl;
    return 0;
}