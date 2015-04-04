#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
const int N = 10001;
// WIN = 1 LOSE = 2;
char d[2][N][N];
inline int lazy_dp (int x, int y) {
	if (x < y)
		swap (x, y);
	if (d[x][y]) {
		return d[x][y];
	}
	for (int i = 0; i < x; ++i) {
		if (lazy_dp(i, y) == 2) {
			d[x][y] = 1;
		}
	}
	for (int i = 0; i < y; ++i) {
		if (lazy_dp(x, i) == 2) {
			d[x][y] = 1;
		}
	}
	for (int i = 1; i <= min (x, y); ++i) {
		if (lazy_dp(x - i, y - i) == 2) {
			d[x][y] = 1;
		}
	}
	if (!d[x][y])
		d[x][y] = 2;
	return d[x][y];
}
int c[51];
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	for (int i = 1; i <= 10
	int t, x, y;
	scanf ("%d", &t);
	++t;
	while (--t) {
		scanf ("%d%d", &x, &y);
		if (lazy_dp (x, y) == 2)
			printf ("%d\n", x ^ y);
		else
			printf ("MANSUR\n");
	}
	return 0;       	
}