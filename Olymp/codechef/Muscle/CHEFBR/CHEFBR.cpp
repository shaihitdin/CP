#include <iostream>
#include <stdio.h>
using namespace std;
int a[101], d[101][101], n;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
	}
	for (int len = 1; len < n; ++len) {
		for (int i = 1; i <= n; ++i) {
			int j = i + len;
			if (i + len > n)
				break;
				d[i][j] = (d[i + 1][j] + d[i][j - 1]);
			if (-a[i] == a[j]) {
				d[i][j] = (d[i][j] * 2) + 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cerr << d[i][j] << " ";
		}
		cerr << "\n";
	}
	return 0;
}