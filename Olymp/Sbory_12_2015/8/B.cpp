#include <bits/stdc++.h>

using namespace std;

const int N = 210;

bool d[N][N][N];
int t[N], w[N];
int n;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> w[i];
	}

	
	d[0][0][0] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 200; ++j) {
			for (int k = 0; k <= 200; ++k) {
				if (j >= t[i])
					d[i][j][k] |= d[i - 1][j - t[i]][k];
				if (k >= w[i])
					d[i][j][k] |= d[i - 1][j][k - w[i]];
			}
		}
	}
	
	for (int j = 0; j <= 200; ++j) {
		for (int k = 0; k <= j; ++k) {
			if (d[n][j][k]) {
				cout << j;
				return 0;
			}
		}
	}
	
	return 0;
}