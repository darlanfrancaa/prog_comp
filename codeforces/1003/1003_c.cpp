#include <iostream>
#include <vector> 
#include <algorithm>
#include <climits>
using namespace std;
const int maxn = 200010;
int dp[maxn];
 
void build(const vector<int>& a, int bla, int num) {
    int n = a.size();
    if (num >= n) return;
 
    if (num == 0) {
        dp[0] = min(a[0], bla - a[0]);
        build(a, bla, 1);
        return;
    }
    if (dp[num - 1] == INT_MIN) {
        dp[num] = INT_MIN;
        build(a, bla, num + 1);
        return;
    }
 
    int x1 = min(a[num], bla - a[num]);
    int x2 = max(a[num], bla - a[num]);
 
    if (dp[num - 1] > x2) {
        dp[num] = INT_MIN; 
    }
    else if (dp[num - 1] <= x1) {
        dp[num] = x1;
    }
    else {
        dp[num] = x2;
    }
 
    build(a, bla, num + 1);
}
 
int main() {
    int k;
    cin >> k;
    while (k > 0) {
        
        for (int i = 0; i < maxn; i++) {
            dp[i] = 0;
        }
 
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int bla;
        cin >> bla;
 
        build(a, bla, 0);
 
        bool invalido = false;
        for (int i = 0; i < n; i++) {
            if (dp[i] == INT_MIN)
                invalido = true;
        }
 
        if (invalido)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
 
        k--;
    }
 
    return 0;
}
 