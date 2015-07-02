#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

int d[N][N];

int a[N];

int main () {
	
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	for (int i = 1; i < N; ++i) {
		for (int j = 1; j <= i; ++j)
			d[i][j] = 0;
		for (int j = i + 1; j < N; ++j)
			d[i][j] = N + 100;
	}
	
	for (int i = 1; i < N; ++i)
		for (int j = 1; j < N; ++j)
			for (int k = 1; j + k < N; ++k)
				d[i][j + k] = min (d[i][j + k], d[i][j] + 1 + d[i][k]);
	
	int test;
	
	scanf ("%d", &test);

	for (int t = 1; t <= test; ++t) {
		int n;
		scanf ("%d", &n);

		for (int i = 1; i <= n; ++i)
			scanf ("%d", &a[i]);

		int ans = 1e9;
		
		for (int i = 1; i < N; ++i) {
			int res = 0;
			for (int j = 1; j <= n; ++j)
				res += d[i][a[j]];
			ans = min (ans, res + i);
		}
		printf ("Case #%d: %d\n", t, ans);

	}
	return 0;
}