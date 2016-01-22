#include <bits/stdc++.h>

using namespace std;

const int N = 310, oo = 1e9;

int d[N][N];
int n, m;

int main () {

	freopen ("weakconn.in", "r", stdin);
	freopen ("weakconn.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	scanf ("%d%d", &n, &m);

	for (int i = 1; i <= n; ++i)	
		for (int j = 1; j <= n; ++j)
			d[i][j] = oo;
	
	for (int i = 1; i <= n; ++i)
		d[i][i] = 0;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf ("%d%d", &x, &y);
		d[x][y] = min (d[x][y], 0);
		d[y][x] = min (d[y][x], 1);
	}
	
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
	
	int ans = 0;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)	
			ans = max (ans, d[i][j]);
	
	printf ("%d", ans);
	
	return 0;
}