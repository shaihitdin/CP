#include <bits/stdc++.h>

using namespace std;

const int bN = 850, N = 500, oo = 1e9;

int n, m;
int d1[N][N], d2[N][N];
bool g[N][N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x][y] = 1;
		g[y][x] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (g[i][j] == 1) {
				d1[i][j] = d1[j][i] = 1;
				d2[i][j] = d2[j][i] = oo;
			} else {
				d1[i][j] = d1[j][i] = oo;
				d2[i][j] = d2[j][i] = 1;
			}
		}
	}
	
	for (int i = 1; i <= n; ++i)
		d1[i][i] = d2[i][i] = 0;
	
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				d1[i][j] = min (d1[i][j], d1[i][k] + d1[k][j]), d2[i][j] = min (d2[i][j], d2[i][k] + d2[k][j]);
	
	if (g[1][n] == 1) {
		if (d2[1][n] != oo)
			cout << d2[1][n];
		else
			cout << -1;
	} else {
		if (d1[1][n] != oo)
			cout << d1[1][n];
		else
			cout << -1;
	}
	
	return 0;
}