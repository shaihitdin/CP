#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
// WIN = 1 LOSE = 2;
int d[1001][1001];
inline int lazy_dp (int x, int y) {
	if (d[x][y]) {
		return d[x][y];
	}
	for (int i = 0; i < x; ++i) {
		if (lazy_dp(i, y) == 2) {
			d[x][y] = 1;
			p[x][y] = {i, y};
		}
	}
	for (int i = 0; i < y; ++i) {
		if (lazy_dp(x, i) == 2) {
			d[x][y] = 1;
			p[x][y] = {i, y};
		}
	}
	for (int i = 1; i <= min (x, y); ++i) {
		if (lazy_dp(x - i, y - i) == 2) {
			d[x][y] = 1;
			p[x][y] = {i, y};
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
	d[0][0] = 2;
	/*
	cnt = 1;
	last = 1;
	ans[1] = 1;
	*/
	vector <int> ahaha, az;
	int last = 0;
	for (int i = 1; i <= 100; ++i) {
		int c = -1;
		for (int j = 0; j <= 100; ++j) {
			if (lazy_dp (i, j) == 2) {
				assert (c == -1);
				c = j;
			}
		}
		cout << i << " : " << c << "\n";
	}
	return 0;
}