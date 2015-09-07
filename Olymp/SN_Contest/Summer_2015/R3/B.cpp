#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3020, M = 110;

ll d[N][M][M][2];
ll n, m, a[N], b[M];

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	cin >> m;

	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	
	sort (b + 1, b + m + 1);
	
	for (int i = 1; i <= n + 1; ++i)
		for (int j = 0; j <= m + 1; ++j)
			for (int k = 0; k <= m + 1; ++k)
				d[i][j][k][0] = d[i][j][k][1] = -1e13;
	
	d[1][1][m][0] = d[1][1][m][1] = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m + 1; ++j) {
			for (int k = m; k >= 0; --k) {
				int v = (i + (j - 1) + (m - k)) & 1;
				//1 - place worst, 2 - place best, 3 - place standard
				for (int l = 0; l < 2; ++l) {
					if (j <= k) {
						if (v == l) {
//							d[i][j + 1][k][l] = max (d[i][j][k][l] + b[j], d[i][j + 1][k][l]);
							d[i][j][k - 1][l] = max (d[i][j][k][l] + b[k], d[i][j][k - 1][l]);
						} else {
							d[i][j + 1][k][l] = max (d[i][j][k][l], d[i][j + 1][k][l]);
//							d[i][j][k - 1][l] = max (d[i][j][k][l], d[i][j][k - 1][l]);
						}
					}
					if (v == l)
						d[i + 1][j][k][l] = max (d[i][j][k][l] + a[i], d[i + 1][j][k][l]);
					else
						d[i + 1][j][k][l] = max (d[i][j][k][l], d[i + 1][j][k][l]);
				}
			}
		}
	}
	
	ll ans = -1e14;
	
	for (int i = 0; i <= m + 1; ++i) {
		for (int j = 0; j < i; ++j) {
			if (n + 1 + (i - 1) + (m - j) == n + m + 1)
			ans = max (ans, d[n + 1][i][j][0]);
			ans = max (ans, d[n + 1][i][j][0]);
			ans = max (ans, d[n + 1][i][j][1]);
			ans = max (ans, d[n + 1][i][j][1]);
		}
	}
	
	
	cout << ans;
	
	return 0;
}