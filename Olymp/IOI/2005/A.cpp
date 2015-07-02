#include <bits/stdc++.h>

using namespace std;

const short N = 300, inf = 32000;

short a[N][N], d[N][N], d1[N][N];

short ans = inf;

#define y1 works

inline short get (const short &x1, const short &y1, const short &x2, const short &y2) {
	return d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1];
}

int main () {

	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	short n, m, q, k;
	
	scanf ("%hd%hd", &n, &m);
	scanf ("%hd%hd", &q, &k);

	for (; q; --q) {
		short i, j;
		scanf ("%hd%hd", &i, &j);
		++a[i][j];
	}
	
	for (short i = 1; i <= n; ++i)
		for (short j = 1; j <= m; ++j)
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a[i][j];
	for (short i = 0; i < N; ++i)
		d1[i][0] = d1[0][i] = inf;
	for (short i = 1; i <= n; ++i) {
		for (short j = 1; j <= m; ++j) {
			short calc = inf;
			for (short it = j; it; --it) {
				short l = 1, r = i + 1;
				while (r - l > 1) {
					short mid = (r + l) >> 1;
					if (get (mid, it, i, j) >= k)
						l = mid;
					else
						r = mid;
				}
				if (get (l, it, i, j) < k)
					continue;
				calc = min ((int)calc, 2 * (i - l + 1) + 2 * (j - it + 1));
				ans = min ((int)ans, 2 * (i - l + 1) + 2 * (j - it + 1) + min (d1[l - 1][m], d1[i][it - 1]));
			}
			d1[i][j] = min (calc, min (d1[i - 1][j], d1[i][j - 1]));
		}
	}
	
	if (ans == inf)
		printf ("NO");
	else
		printf ("%hd", ans);

	return 0;
}