#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    string a, b; 
    cin >> n >> a >> m >> b;
    int i=0;
    while( i < n && i < m &&  a[i]==b[i] ) i++;
    cout <<  i << endl;
    return 0;
}