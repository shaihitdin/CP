#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int row[N], col[N], a[N][N];

int ans_row[N], ans_col[N];

inline void del_row (int x, int y) {
	for (int i = 1; i <= 100; ++i)
		a[x][i] -= y;
	ans_row[x] += y;
	row[x] -= y;
}

inline void del_col (int x, int y) {
	for (int i = 1; i <= 100; ++i)
		a[i][x] -= y;
	ans_col[x] += y;
	col[y] -= y;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= 100; ++i)
		row[i] = col[i] = 1e9;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			row[i] = min (a[i][j], row[i]);
			col[j] = min (a[i][j], col[j]);
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] > row[i] + col[j]) {
				cout << -1;
				return 0;
			}
		}
	}

	a[0][0] = 1e9;
	while (1) {
		int x = 0, y = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (a[i][j] != 0 && a[x][y] > a[i][j]) {
					x = i;
					y = j;
				}
			}
		}
		if (x == 0 && y == 0)
			break;
		int can = min (row[x], a[x][y]);
		del_row (x, can);
		can = min (col[y], a[x][y]);
		del_col (y, can);
	}


	int ans_sz = 0;
	for (int i = 1; i <= 100; ++i)
		ans_sz += ans_row[i] + ans_col[i];
	
	cout << ans_sz << "\n";
	for (int i = 1; i <= 100; ++i) {
		while (ans_row[i]--)
			cout << "row " << i << "\n";
		while (ans_col[i]--)
			cout << "col " << i << "\n";

	}
	
	
	return 0;
}