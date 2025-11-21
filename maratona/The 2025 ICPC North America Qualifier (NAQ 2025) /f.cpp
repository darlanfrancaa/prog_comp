#include <bits/stdc++.h>
using namespace std;

#define int long long
using pii = pair<int,int>;
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
     int n, k; cin >> n >> k;
     vector<int> notas(n);
     
     for(int i = 0; i < n; i++){
        cin >> notas[i];
     }

     sort(notas.begin(), notas.end());
     
     int prefs[n+10];
     int prefsq[n+10];

     prefs[0] = 0;
     prefsq[0] = 0;

     for(int i = 1; i <= n;i++){
        prefs[i] = prefs[i-1] + notas[i-1];
        prefsq[i] = prefsq[i-1] + notas[i-1] * notas[i-1];
     }

     double menornota = 1e18;
     for(int i = 1; i + k - 1 <= n; i++){
        int lim = i + k - 1;
        int sum = prefs[lim] - prefs[i-1];
        int sumq = prefsq[lim] - prefsq[i-1];

        double novanota = sumq - (double)sum*sum/k;
        menornota = min(menornota, novanota);
     }
     cout << fixed << setprecision(7) << menornota;
     
    return 0;
}