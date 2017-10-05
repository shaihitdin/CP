#include <bits/stdc++.h>

using namespace std;

const int N = 110;

double ans[N][N];
long long dist[N][N], e[N], s[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int t;
	cin >> t;

	for (int _ = 1; _ <= t; ++_) {
		cout << "Case #" << _ << ": ";
		int n, q;
		cin >> n >> q;
		for (int i = 1; i <= n; ++i)
			cin >> e[i] >> s[i];
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> dist[i][j];
				if (dist[i][j] == -1)
					dist[i][j] = 1e18;
			}
		}
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (e[i] >= dist[i][j])
					ans[i][j] = dist[i][j] / ((double) s[i]);
				else
					ans[i][j] = 1e18;
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					ans[i][j] = min (ans[i][j], ans[i][k] + ans[k][j]);
		while (q--) {
			int x, y;
			cin >> x >> y;
			cout << fixed;
			cout << setprecision (7);
			cout << ans[x][y] << " ";
		}
		cout << "\n";
	}

	return 0;
}