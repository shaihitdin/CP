/*
ID: shaihit1
PROG: combo
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[4][4], ans;

inline int diff (const int &a, const int &b) {
	return min (abs (a - b) % n, min (abs (a + n - b) % n, abs (b + n - a) % n));
}

inline bool can (const int &x, const int &y, const int &z, const int &a, const int &b, const int &c) {
	return diff (x, a) <= 2 && diff (y, b) <= 2 && diff (z, c) <= 2;
}

int main() {

	freopen ("combo.in", "r", stdin);
	freopen ("combo.out", "w", stdout);
	
	scanf ("%d", &n);
	for (int i = 1; i <= 2; ++i)
		for (int j = 1; j <= 3; ++j)
			scanf ("%d", &a[i][j]);
	for (int x = 1; x <= n; ++x)
		for (int y = 1; y <= n; ++y)
			for (int z = 1; z <= n; ++z)
				if (can (x, y, z, a[1][1], a[1][2], a[1][3]) || (can (x, y, z, a[2][1], a[2][2], a[2][3])))
					++ans;
    printf ("%d\n", ans);
	return 0;
}
