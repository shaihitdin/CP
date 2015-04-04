#include <iostream>
#include <stdio.h>
using namespace std;
// direction  (1) = /, (2) = \, (3) = |, (4) = -
int main () {
	freopen ("G.in", "r", stdin);
	freopen ("G.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf ("%d", &a[i][j]);
		}
	}
	for (int k = 1; k <= 4; ++k) {
		for (int step = 1; step <= n; ++step) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (k == 1) {
						d[k][i][j] = d[k][i + 1][j - 1]
					}
					if (k == 2) {
					
					}
					if (k == 3) {
					
					}
					if (k == 4) {
					
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
		
		}
	}
	return 0;
}