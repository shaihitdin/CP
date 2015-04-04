#include <iostream>
#include <stdio.h>
using namespace std;
const int inf = 1e9;
const int N = 101;
int n, a[N];
int d[N][N], pos[N][N];
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			d[i][j] = inf;
	for (int i = 1; i <= n; ++i)
		d[i][i] = a[i] * (a[i - 1] + a[i + 1]);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < i; ++j)
			d[i][j] = 0;
	for (int len = 1; len < n; ++len) {
		for (int l = 2; l < n; ++l) {
			int r = l + len;
			if (r == n)	break;
			for (int j = l; j <= r; ++j) {
				if (d[l][r] > d[l][j - 1] + d[j + 1][r] + a[j] * (a[l - 1] + a[r + 1]) )
					d[l][r] = d[l][j - 1] + d[j + 1][r] + a[j] * (a[l - 1] + a[r + 1]);
			}
		}
	}
	cout << d[2][n - 1];
	return 0;
}