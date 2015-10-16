#include <bits/stdc++.h>

using namespace std;

const int N = 1100, oo = 1e9;

int n;
int a[N], d[N][N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			d[i][j] = -oo;
		}
	}
	
	if (a[1] < 0) {
		cout << -1;
		return 0;
	}
	
	d[1][1] = a[1];

	for (int i = 2; i < n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[i - 1][j] - 100 >= 0)
				d[i][j] = max (d[i][j], d[i - 1][j] - 100);
			if (d[i - 1][j - 1] >= 0 && d[i - 1][j - 1] + a[i] >= 0)
				d[i][j] = max (d[i][j], d[i - 1][j - 1] + a[i]);
		}
	}
	
	if (n == 1) {
		cout << 1;
	} else {
		for (int j = 1; j <= n; ++j) {
			/*
			if (d[n - 1][j] - 100 >= 0) {
				cout << j;
				return 0;
			}
			*/
			if (d[n - 1][j - 1] >= 0 && d[n - 1][j - 1] + a[n] >= 0) {
				cout << j;
				return 0;
			}
		}
		cout << -1;
	}
	
	return 0;
}