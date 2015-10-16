#include <bits/stdc++.h>

using namespace std;

const int N = 110, K = 310;

int d[N * N][K];
int n, t;
int a[N * N];
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
	
	if (t <= n) {
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
		
		for (int i = sqr_n; i >= sqr_n - n + 1; --i) {
			for (int j = 1; j < K; ++j)
				ans = max (ans, d[i][j]);
			ans = max (ans, d[i][a[i]] + (t - (((i - 1) / n) + 1)) * cnt[a[i]]);
		}
	}
	
	cout << ans;
	
	return 0;
}