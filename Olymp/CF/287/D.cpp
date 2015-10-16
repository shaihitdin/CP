#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1005;
int n, k, m, ans;
int d[N][101][2]; // 1 - N, 2 - mod
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	cin >> n >> k >> m;
	d[0][0][0] = 1;
	int base = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			for (int digit = (i == n - 1); digit < 10; ++digit) {
				int cj = (j + base * digit) % k;
				d[i + 1][cj][1] += d[i][j][1];
				d[i + 1][cj][1] %= m;
				if (!cj && digit)
					d[i + 1][cj][1] += d[i][j][0];
				else
					d[i + 1][cj][0] += d[i][j][0];
				d[i + 1][cj][1] %= m;
				d[i + 1][cj][0] %= m;
			}
		}
		base = (base * 10) % k;
	}
	for (int i = 0; i < k; ++i)
		ans += d[n][i][1], ans %= m;
	cout << ans;
	return 0;
}