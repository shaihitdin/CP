#include <bits/stdc++.h>

using namespace std;

const int N = 110, oo = 1e9;

int a[N][N], b[N][N];
int n, m, q;

inline void do_floyd () {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			b[i][j] = a[i][j];
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				b[i][j] = min (b[i][j], b[i][k] + b[k][j]);
}

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m >> q;

	for (int i = 1; i <= n; ++i)	
		for (int j = 1; j <= n; ++j)
			a[i][j] = oo;
	
	for (int i = 1; i <= n; ++i)
		a[i][i] = 0;
	
	
	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}

	while (q--) {
		char q_type;
		int x, y;
		cin >> q_type >> x >> y;
		if (q_type == '+') {
			a[x][y] = a[y][x] = 1;
		} else if (q_type == '-') {
			a[x][y] = a[y][x] = oo;
		} else {
			if (x == y) {
				cout << 0 << "\n";
				continue;
			}
			do_floyd ();
			if (b[x][y] == oo)
				cout << -1 << "\n";
			else
				cout << b[x][y] - 1 << "\n";
		}
	}
	
	return 0;
}