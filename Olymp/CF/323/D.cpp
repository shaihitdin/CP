#include <bits/stdc++.h>

using namespace std;

const int N = 120, K = 310;

typedef long long ll;

int d[2 * N * N][K], d2[2 * N * N][K];
int n, t;
int a[2 * N * N];
int cnt[K];

int main () {
	
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> t;

	int sqr_n = n * n;
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	int ans = 0;
	
	if (t <= n + n) {
		sqr_n = n * t;
		for (int i = n + 1; i <= sqr_n; ++i)
			a[i] = a[i - n];
		for (int i = 1; i <= sqr_n; ++i) {
			for (int j = 1; j < K; ++j)
				d[i][j] = max (d[i - 1][j], d[i][j - 1]);
			++d[i][a[i]];
			for (int j = 1; j < K; ++j)
				d[i][j] = max (d[i][j], max (d[i - 1][j], d[i][j - 1]));
		}
		for (int i = 1; i <= sqr_n; ++i) {
			for (int j = 1; j < K; ++j)
				ans = max (ans, d[i][j]);
		}
	} else {
		for (int i = n + 1; i <= sqr_n; ++i)
			a[i] = a[i - n];
		for (int i = 1; i <= sqr_n; ++i) {
			for (int j = 1; j < K; ++j)
				d[i][j] = max (d[i - 1][j], d[i][j - 1]);
			++d[i][a[i]];
			for (int j = 1; j < K; ++j)
				d[i][j] = max (d[i][j], max (d[i - 1][j], d[i][j - 1]));
		}

		for (int i = 1; i <= n; ++i)
			++cnt[a[i]];
		
		for (int i = sqr_n; i >= 1; --i) {
			for (int j = K - 2; j >= 1; --j)
				d2[i][j] = max (d2[i + 1][j], d2[i][j + 1]);
			++d2[i][a[i]];
			for (int j = K - 2; j >= 1; --j)
				d2[i][j] = max (d2[i][j], max (d2[i + 1][j], d2[i][j + 1]));
		}
		
		for (int i = sqr_n; i >= sqr_n - n + 1; --i) {
			for (int j = 1; j < K; ++j)
				ans = max (ans, d[i][j]);
			ans = max (ans, d[i][a[i]] + (t - n - n) * cnt[a[i]] + d2[1][a[i]]);
		}
	}
	
	cout << ans;
	
	return 0;
}