#include <bits/stdc++.h>

using namespace std;

const int bpr = 1e9 + 7, N = 1230;

int dp[N][N];
int n, a[N], f[N], rf[N];
bool is[N][N];

inline void add (int &x, const int &y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

inline int bin_pow (int a, int b) {
	if (!b)
		return 1;
	if (b & 1)
		return bin_pow (a, b - 1) * 1ll * a % bpr;
	int c = bin_pow (a, b / 2);
	return c * 1ll * c % bpr;
}

inline int cnk (int n, int k) {
	int ans = f[n];
	ans = ans * 1ll * rf[k] % bpr;
	ans = ans * 1ll * rf[n - k] % bpr;
	return ans;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	dp[1][n] = 1;

	for (int i = f[0] = 1; i < N; ++i)
		f[i] = f[i - 1] * 1ll * i % bpr;
	for (int i = 0; i < N; ++i)
		rf[i] = bin_pow (f[i], bpr - 2);
	
	for (int i = 1; i <= n; ++i) {
		is[i][i] = 1;
		for (int j = i + 1; j <= n; ++j)
			is[i][j] = (is[i][j - 1] & (a[j - 1] <= a[j]));
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; i + j - 1 <= n; ++j) {
			if (!is[i][i + j - 1])
				continue;
			for (int k = j; k <= n; ++k) {
				if (i > 1)
					add (dp[i + j][j], dp[i][k] * 1ll * 1ll * cnk (k, k - j) % bpr * f[j] % bpr);
			 	else
			 		add (dp[i + j][j], dp[i][k] % bpr);
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		add (ans, dp[n + 1][i]);

	cout << ans;
	return 0;
}