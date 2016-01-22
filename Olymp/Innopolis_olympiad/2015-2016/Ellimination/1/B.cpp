#include <bits/stdc++.h>

using namespace std;

const int bpr = 1e9 + 7;

int n, m, d[10001][10001];


int main () {
	
	freopen ("ticket-office.in", "r", stdin);
	freopen ("ticket-office.out", "w", stdout);

	cin >> n >> m;

	d[0][0] = 1;

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m && i >= j * 9; ++j) {
			if (i) {
				d[i][j] += d[i - 1][j];
				if (d[i][j] >= bpr)
					d[i][j] -= bpr;
			}
			if (j) {
				d[i][j] += d[i][j - 1];
				if (d[i][j] >= bpr)
					d[i][j] -= bpr;
			}
		}
	}
	
	cout << d[n][m];
	
	return 0;
}