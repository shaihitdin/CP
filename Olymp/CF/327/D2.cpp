#include <bits/stdc++.h>

using namespace std;

const int N = 152, oo = 1e9;

int d[2852][N][N];
int n, k, s;
int a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> k >> s;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	if (s >= 2850) {
		sort (a + 1, a + n + 1);
		int sum = 0;
		for (int i = 1; i <= k; ++i)
			sum += a[i];
		cout << sum;
		return 0;
	}

	for (int i = 0; i <= s + 1; ++i)
		for (int j = 0; j <= n + 1; ++j)
			for (int it = 0; it <= k + 1; ++it)
				d[i][j][it] = oo;
	
	d[s][1][1] = 0;
	
	for (int i = s; i >= 0; --i) {
		for (int j = 1; j <= n; ++j) {
			for (int it = 1; it <= j + 1 && it <= k + 1; ++it) {
				if (d[i][j][it] == oo)
					continue;
				if (i >= j - it)
					d[i - (j - it)][j + 1][it + 1] = min (d[i - (j - it)][j + 1][it + 1], d[i][j][it] + a[j]);
		   		d[i][j + 1][it] = min (d[i][j + 1][it], d[i][j][it]);
			}
		}
	}
	
	int ans = oo;
	
	for (int i = 0; i <= s; ++i)
		ans = min (ans, d[i][n + 1][k + 1]);
	
	cout << ans;
	
	return 0;
}