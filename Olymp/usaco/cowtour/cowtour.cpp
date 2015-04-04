/*
ID: shaihit1
PROG: cowtour
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 151, inf = 1e9 + 7;

double d[N][N], mx[N], ans = inf;
int c[N][N], a[N], b[N];
int n;
inline int sqr (int && asd) {
	return asd * asd;
}

int main() {

	freopen ("cowtour.in", "r", stdin);
	freopen ("cowtour.out", "w", stdout);

	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%d%d", &a[i], &b[i]);

	getchar ();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			c[i][j] = getchar() - '0';
		}
		getchar();
	}	
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			d[i][j] = (c[i][j]) ?  sqrt (sqr (a[i] - a[j]) + sqr (b[i] - b[j])) : inf;
	for (int i = 1; i <= n; ++i)
		d[i][i] = 0;
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				d[i][j] = min (d[i][j], d[i][k] + d[k][j]);	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (d[i][j] != inf)
				mx[i] = max (mx[i], d[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (d[i][j] == inf) {
				int v1 = i, v2 = j;
				for (int k = 1; k <= n; ++k)
					if (d[k][i] != inf && d[v1][i] < d[k][i])
						v1 = k;
				for (int k = 1; k <= n; ++k)
					if (d[k][j] != inf && d[v2][j] < d[k][j])
						v2 = k;
				ans = min (ans, max (max (mx[i], mx[j]), d[v1][i] + d[v2][j] + sqrt (sqr (a[i] - a[j]) + sqr (b[i] - b[j]))));
			}
	for (int i = 1; i <= n; ++i)
		ans = max (ans, mx[i]);
	printf ("%.6lf\n", ans);	
	return 0;
}
