#include <bits/stdc++.h>

using namespace std;

const int N = 301;

bool a[N][N], rev_a[N][N];

int main () {
	
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char x;
			cin >> x;
			x -= '0';
			a[i][j] = x;
		}
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			rev_a[i][m - j + 1] = a[i][j];
	
	for (int len = 1; len <= min (n, m); ++len) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				int rev_j = m - j + 1;
				if (len <= 2) {
				
				} else {
					dp[len][i][j] = min (dp[len][i + 1][j], check (w));
				}
			}
		}
	}
	
	return 0;
}