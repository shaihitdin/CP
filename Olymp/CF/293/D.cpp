#include <bits/stdc++.h>

using namespace std;

const int N = 2002;

double d[N][N], ans;


int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio (0);
	int n, t;
	double p;
	cin >> n >> p >> t;
	d[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < t; ++j) {
			d[i][j + 1] += (d[i][j] * (1.0 - p));
			d[i + 1][j + 1] += (d[i][j] * p);
		}
	}
	for (int j = 0; j < t; ++j)
		d[n][j + 1] += d[n][j];
	cerr << fixed;
	cout << fixed;
	cout.precision (6);
	cerr.precision (6);
	/*
	for (int i = 0; i <= n; ++i)
		cerr << i << " " <<  d[i][t] << "\n";
	*/
	for (int i = 0; i <= n; ++i)
		ans += (d[i][t] * i);
	cout << ans;
	return 0;
}