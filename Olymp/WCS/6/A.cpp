#include <bits/stdc++.h>

using namespace std;

const int bpr = 175781251, N = 110 * 110;

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

int pw2[N], cnk[1100][1100];
int dp[110][N];

inline int bin_pow (int x, int y) {
	if (!y)
		return 1;
	if (y & 1)
		return (bin_pow (x, y - 1) * 1ll * x) % bpr;
	int c = bin_pow (x, y / 2);
	return (c * 1ll * c) % bpr;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	pw2[0] = 1;

	for (int i = 1; i < N; ++i) {
		pw2[i] = pw2[i - 1];
		add (pw2[i], pw2[i - 1]);
	}
	
	cnk[0][0] = 1;
	
	for (int i = 1; i < 1100; ++i) {
		cnk[i][i] = cnk[i][0] = 1;
		for (int j = 1; j < i; ++j) {
			cnk[i][j] = cnk[i - 1][j];
			add (cnk[i][j], cnk[i - 1][j - 1]);
		}
	}
	
	cout << "{0,\n";

	for (int i = 1; i <= 100; ++i) {
		int ans = 1;
		for (int j = 1; j <= i; ++j) {
			for (int k = j; j + k <= i; ++k) {
				//int unused = i - (j + k);
				memset (dp, 0, sizeof (dp));
				dp[0][0] = 1;
				for (int k3 = 1; k3 <= k; ++k3) {				
					for (int k4 = 0; k4 <= j * k; ++k4) {
						for (int k2 = 1; k2 <= min (k4, j); ++k2) {
							add (dp[k3][k4], (dp[k3 - 1][k4 - k2] * 1ll * cnk[j][k2]) % bpr);
						}
					}
				}
				int val3 = 0;
				for (int k2 = 0; k2 <= j * k; ++k2) {
					int val2 = dp[k][k2];
					val2 = (val2 * 1ll * cnk[i][j + k]) % bpr;
					val2 = (val2 * 1ll * cnk[j + k][j]) % bpr;
					val2 = (val2 * 1ll * pw2[k2]) % bpr;
					add (val3, val2);
				}
				if (j == k) {
					val3 = (val3 * 1ll * bin_pow (2, bpr - 2)) % bpr;
				}
				add (ans, val3);
			}
		}
		//ans = (ans * 1ll * bin_pow (2, bpr - 2)) % bpr;
		cout << ans << ",\n";
	}

	cout << "};";
	
	return 0;
}