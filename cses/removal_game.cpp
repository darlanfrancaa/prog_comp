#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
	vector<long long> seq(n);
	for (int i = 0; i < n; i++) cin >> seq[i];
	vector<vector<long long>> dp(n, vector<long long>(n));
	vector<vector<long long>> soma(n, vector<long long>(n,0));
	vector<long long> prefix(n, 0);
	prefix[0] = seq[0];
	for (int i = 1; i<n; i ++) {
		prefix[i] = prefix[i - 1] + seq[i];
	}
	for (int i = 0; i < n; i++) soma[0][i] = prefix[i];
 
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) {
			soma[i][j] = prefix[j] - prefix[i - 1];
		}
	}
	for (int i = 0; i < n; i++) dp[i][i] = seq[i];
	for (int i = 0; i < n - 1; i++) dp[i][i + 1] = max(seq[i], seq[i + 1]);
	for (int k = 2; k <= n - 1; k++) {
		for (int i = 0; i + k <= n - 1; i++) {
			dp[i][i + k] = max((seq[i] + soma[i + 1][i + k] - dp[i + 1][i + k]), (seq[i + k] + soma[i][i + k - 1] - dp[i][i + k - 1]));
		}
	}
	cout << dp[0][n - 1];
    return 0;
}