#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct Graze{
    int x,y,t;
    bool operator<(const Graze&g) const{
        return t< g.t;
    }
};

bool cant_reach(Graze g1, Graze g2){
    ll time = g1.t - g2.t;
    ll x = g1.x - g2.y;
    ll y = g1.y - g2.y;
    return time*time < x*x + y*y;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int g,n; cin >> g >> n;
    vector<Graze> a(g);
    for(int i=0;i<g;i++){
        cin >> a[i].x >> a[i].y >> a[i].t;
    }
    sort(a.begin(),a.end());
    int ans = 0;
    for(int i=0;i<n;i++){
        bool crime = true;
        int x,y,t; cin >> x >> y >> t;
        auto p = upper_bound(a.begin(),a.end(),Graze{0,0,t});
        Graze tmp{x,y,t};
        
        if(p!= a.end()){
            if(cant_reach(tmp,*p)){
                crime = false;
            }
        }
        if(p > a.begin()){
            if(cant_reach(tmp,*(p-1))){
                crime = false;
            }
        }
        if(!crime) ans++;    
        
    }   
    cout << ans;
    return 0;
}
