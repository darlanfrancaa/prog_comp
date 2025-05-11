#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

// entao eu quero o k tal que  sum piso(k/i) seja maior do que t

ll n, t; 
vector<ll> machines;

bool maior_que_t(ll k){
    ll sum = 0;
    for(auto &machine: machines) sum += (k/machine);
    return sum >= t;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> t; 
    machines.resize(n);
    ll minimo=INT_MAX;
    for(auto &machine : machines) {
        cin >> machine;
        minimo = min(minimo,machine);
    }
    ll left = 1, right = minimo*t;
    while(left < right){
        ll mid = left + (right - left)/2;
        if(maior_que_t(mid)) right = mid;
        else left = mid + 1;
    }
    cout << left << endl; 
    return 0;
}