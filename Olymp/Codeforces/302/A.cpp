#include <bits/stdc++.h>

using namespace std;

const int N = 501;
int n, m, b, a[N], mod;
int d[N][N];

int main () {

	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	cin >> n >> m >> b >> mod;

	d[0][0] = 1;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int k = 1; k <= n; ++k)
		for (int i = 0; i < m; ++i)
			for (int j = 0; j + a[k] <= m; ++j)
				d[i + 1][j + a[k]] += d[i][j], d[i][j] %= mod;

	int ans = 0;
	
	for (int i = 0; i <= b; ++i) {
		ans = (ans + d[m][i]) % mod;
	}

	cout << ans;

	return 0;
}