#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int>> pontos(n + 2);

	unordered_map<int, vector<int>> lines[2];
	for (int i = 0; i < n + 2; i++) {
		cin >> pontos[i].first >> pontos[i].second;
		lines[0][pontos[i].first].push_back(i);
		lines[1][pontos[i].second].push_back(i);
	}

	queue<pair<int, bool>> q;
	q.push({0, true});
	q.push({0, false});

	vector<int> dist(n + 2, 1e9);
	dist[0] = 0;

	while (!q.empty()) {
		auto [atual,eixo] = q.front(); q.pop();
		int dir = (eixo ? 0 : 1);
		int coord = (eixo ? pontos[atual].first : pontos[atual].second);
		for (int point : lines[dir][coord]) {
			if (dist[point] == 1e9) {
				q.push({point, !eixo});
				dist[point] = dist[atual] + 1;
			}
		}
	}
	cout << (dist[1] == 1e9 ? -1 : dist[1] - 1) << endl;
	return 0;
}