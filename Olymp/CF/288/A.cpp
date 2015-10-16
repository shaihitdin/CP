#include <bits/stdc++.h>

using namespace std;

int n, m, k, a, b;
int d[1001][1001];
inline bool can (const int &x, const int &y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, +1, -1, +1};
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);
	cin >> n >> m >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> a >> b;
		d[a][b] = 1;
		for (int j = 0; j < 4; ++j) {
			if (can (a + dx[j], b + dy[j]) && d[a + dx[j]][b] && d[a][b + dy[j]] && d[a + dx[j]][b + dy[j]]) {
				cout << i;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}