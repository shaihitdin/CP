#include <iostream>
#include <stdio.h>
using namespace std;
const short N = 1501;
short d[N][N];
short n, m, d1[N][N];
char a[N][N];
int main () {
	freopen ("C.in", "r", stdin);
	freopen ("C.out", "w", stdout);
	scanf ("%d%d\n", &n, &m);
	for (short i = 1; i <= n; ++i) {
		for (short j = 1; j <= m; ++j) {
			scanf ("%c", &a[i][j]);
		}
		scanf ("\n");
	}
	for (short i = 1; i <= n; ++i) {
		for (short j = 1; j <= m; ++j) {
			if (a[i][j] == '1') {
				d[i][j] = d[i][j - 1] + 1;
				d1[i][j] = d1[i - 1][j] + 1;
			}
		}
	}
	short ans = -1;
	for (short i = 1; i <= n; ++i) {
		for (short j = 1; j <= m; ++j) {
			if (a[i][j] != '1')
				continue;
			short len = min (d[i][j], d1[i][j]);
			for (; len >= ans; --len) {
				if (d[i - (len - 1)][j] >= len && d1[i][j - (len - 1)] >= len)
					ans = len;
			}
		}
	}
	if (ans == -1)
		ans = 0;
	printf ("%d", ans);
	return 0;
} 