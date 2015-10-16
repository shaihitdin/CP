#include <bits/stdc++.h>

using namespace std;

const int N = 1010, K = 10, L = 160, oo = 1e9;

inline int calc (const int &l, const int &r, const int &x) {
	int lx = l, rx = r;
	for (int i = (__builtin_popcount (r - l + 1) == 1) ? (lg[r - l + 1] - 1) : lg[r - l + 1]; i >= 0; --i) {
	
	}
	int ly = l, ry = r;
	for (int i = (__builtin_popcount (r - l + 1) == 1) ? (lg[r - l + 1] - 1) : lg[r - l + 1]; i >= 0; --i) {
	
	}

}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	
	for (int i = 2; i <= n; ++i)
		lg[i] = lg[i / 2] + 1;
	
	for (int step = 0; step <= lg[n]; ++step)
		for (int i = 1; i <= n; ++i)
			for (int j = -80; j <= 80; ++j)
				d[step][i][j + 80] = oo;
	
	for (int i = 1; i <= n; ++i)
		for (int j = -80; j <= 80; ++j)
			d[0][i][j + 80] = abs (a[i] + j - b[i]);
	
	for (int step = 1; step <= lg[n]; ++step) {
		for (int i = 1; i + (1 << step) - 1 <= n; ++i) {
			for (int j = -80; j <= 80; ++j) {
				d[step][i][j + 80] = calc (i, i + (1 << step) - 1, j);
			}
		}
	}
	
	
	
	return 0;
}