#include <bits/stdc++.h>

using namespace std;

const int N = 3001;

char a[N][N], ans[N][N];
int n, m, shift;
int row_m[N], row_g[N];
int main () {

	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> m;
	memset (ans, '.', sizeof (ans));
	for (int i = 1; i <= m; ++i)
		row_m[i] = 0, row_g[i] = n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 'X') {
				row_m[j] = max (i, row_m[j]);
			}
			else if (a[i][j] == '#') {
				ans[i][j] = '#';
				row_g[j] = min (row_g[j], i);
			}			
		}
	}
	shift = 1001;
	for (int i = 1; i <= m; ++i) {
		if (row_m[i] == 0)
			continue;
		shift = min (shift, row_g[i] - row_m[i] - 1);
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) 
			if (a[i][j] == 'X')
				ans[i + shift][j] = 'X';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << ans[i][j];
		}
		cout << "\n";
	}
	return 0;
}