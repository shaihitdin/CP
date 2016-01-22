#include <bits/stdc++.h>

using namespace std;

const int N = 203;

int n, m, a, b, p;

int c[N][N][N];

int pre[1000][1000];

int main () {

	freopen ("matrix.in", "r", stdin);
	freopen ("matrix.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	scanf ("%d%d", &m, &n);

	scanf ("%d%d", &a, &b);

	scanf ("%d", &p);

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				scanf ("%d", &c[i][j][k]);
			}
		}
	}	
	
	for (int i = 1; i <= n; ++i)
		c[0][i][i] = 1;
	
	for (int i = 0; i < p; ++i)
		for (int j = 0; j < p; ++j)
			pre[i][j] = (i * j) % p;
	
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			c[m + 1][a][j] = 0;
			for (int k = 1; k <= n; ++k) {
				c[m + 1][a][j] += pre[c[0][a][k]][c[i][k][j]];
				if (c[m + 1][a][j] >= p)
					c[m + 1][a][j] -= p;
			}
		}
		for (int j = 1; j <= n; ++j)
			c[0][a][j] = c[m + 1][a][j];
	}
	
	printf ("%d", c[0][a][b]);
	
	return 0;
}