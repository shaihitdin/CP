#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e4 + 1;
int t, n, x, sum;
bool d[N][101];
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &t);
	for (int test = 1; test <= t; ++test) {
		scanf ("%d", &n);
		memset (d, 0, sizeof(d));
		d[0][0] = 1;
		sum = 0;
		for (int i = 1; i <= n; ++i) {
			scanf ("%d", &x);
			sum += x;
			for (int j = 0; j <= 100; ++j) {
				if (d[i - 1][j] && j + x <= 100)
					d[i][j + x] = 1;
				if (d[i - 1][j] && x != 0 && j + x - 1 <= 100)
					d[i][j + x - 1] = 1;
			}
		}
		if (d[n][99] && sum != 99)
			puts ("YES");
		else
			puts ("NO");
	}
	return 0;
}