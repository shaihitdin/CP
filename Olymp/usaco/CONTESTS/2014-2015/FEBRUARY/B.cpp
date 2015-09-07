#include <bits/stdc++.h>

using namespace std;

const int bpr = 1e9 + 7;

const int N = 101;

int n, m, k, a[N][N], d[N][N];

int main () {
	freopen ("hopscotch.in", "r", stdin);
	freopen ("hopscotch.out", "w", stdout);

	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf ("%d", &a[i][j]);

	d[1][1] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k1 = i + 1; k1 <= n; ++k1) {
				for (int k2 = j + 1; k2 <= m; ++k2) {
					if (a[i][j] != a[k1][k2]) {
						d[k1][k2] += d[i][j];
						if (d[k1][k2] >= bpr) {
							d[k1][k2] -= bpr;
						}
					}
				}
			}
		}
	}

	printf ("%d", d[n][m]);

	return 0;
}