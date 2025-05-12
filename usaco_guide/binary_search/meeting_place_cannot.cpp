#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
using pii = pair<double,double>;

// link do problema : https://codeforces.com/contest/782/problem/B

// eu moralmente quero o ponto x do plano que satisfaz max ( |x - xi|/vi) ser minimo possivel dentre todas as possibilidades de x,
/*
    entao peguemos um cara t 
    isso quer dizer que | x - xi | <= vi . t 
    o que implica qie - vi t <= x - xi <= vi t 
    ou seja xi - vi t  <= x <= vi t + xi 

    5 <=  x <= 9
    - 3 <= x  <=  5
    1 <= x <= 5


*/

int n; 

bool interseccao(const vector<pii> &intervalos){
    double begin = intervalos[0].first;
    double end = intervalos[0].second;
    for(const auto& [left,right]: intervalos){
        begin = max(begin, left);
        end = min(end, right);
        if(begin > end) return false;
    }
    return true;
}

bool its_possible(double t, const vector<double> &x, const vector<double> &v){
    vector<pii> intervalos(n);
    for(int i=0;i<n;i++){
        intervalos[i] = {x[i]-v[i]*t,x[i]+v[i]*t};
    }
    return interseccao(intervalos);
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<double> x(n);
    for(auto &_:x) cin >> _;
    vector<double> v(n);
    for(auto &_:v) cin >> _;
    double left = 0.0 , right = 1e9, mid;
    for(int i=0;i<100;i++){
        mid = (left + right)/2;
        if(its_possible(mid,x,v)) right = mid;
        else left = mid;
    }
    cout << fixed << setprecision(10) << right << endl;
    return 0;
}