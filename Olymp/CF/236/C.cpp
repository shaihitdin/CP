#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int t;
int a[30][30], n, p, cnt;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	srand (4542648);
	scanf ("%d", &t);
	for (int test = 1; test <= t; ++test) {
		for (int i = 1; i <= 24; ++i)
			for (int j = 1; j <= 24; ++j)
				a[i][j] = 0;
		scanf ("%d%d", &n, &p);
		cnt = 2 * n + p;
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					if (!a[i][j] && j != i) {
						a[i][j] = 1;
						a[j][i] = 1;
						--cnt;
						if (!cnt) {
							goto here;
						}
					}
		here:;
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j)
				if (a[i][j])
					printf ("%d %d\n", i, j);
	}
	return 0;
}