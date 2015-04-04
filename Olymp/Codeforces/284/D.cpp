#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 5010;
int n, T;
int t[N];
double d[N][N], p[N];
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio(0);
	cin >> n >> T;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i] >> t[i];
	}
	d[1][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= T; ++j) {
			d[i + 1][j] += (d[i][j] / 100 * p[i]); 
			d[i][j + 1] += d[i][j];
			if (t[i] <= j) {
				d[i + 1][j - t[i]] += d[i][j - t[i]];
			}
		}
	}
	cout << fixed;
	cout.precision (6);
	cerr << fixed;
	cerr.precision (6);
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 0; j <= T; ++j) {
			cerr << d[i][j] << " ";
		}
		cerr << "\n";
	}
	return 0;
}