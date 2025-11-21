#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> a;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> s;
    s.resize(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    vector<double> resp;
    resp.resize(n+1);
    resp[0] = 0;
    int soma = 0;

    for(int i = n-1; i >= 0; i--){
        soma += s[i];
        resp[n-i] = ( soma + a[n-i-1] ) * (1.0) / (n-i)*(1.0);
    }
    sort(resp.begin(), resp.end());
    
    cout << fixed << setprecision(6) << resp[n];



    return 0;
}