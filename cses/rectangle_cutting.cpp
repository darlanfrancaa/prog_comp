#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
const int mod = 1e9 + 7;

int dp[510][510];
 
int solve(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	if (i == j) return dp[i][j] = 0;
	dp[i][j] = INT_MAX;
	for (int k = 1; k < i; k++) {
		dp[i][j] = min(solve(k,j) + solve(i-k,j) + 1, dp[i][j]);
	}
	for (int k = 1; k < j; k++) {
		dp[i][j] = min(solve(i, j-k) + solve(i, k) + 1, dp[i][j]);
	}
	return dp[i][j];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof dp);
	int a, b; cin >> a >> b;
	cout << solve(a, b);
    return 0;
}