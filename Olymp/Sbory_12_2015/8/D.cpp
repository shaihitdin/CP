#include <bits/stdc++.h>

using namespace std;

const int bpr = 1e9 + 7, N = 1010, K = 50;

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

int d[N][K][N], c[N][K][N];
int cnk[N][N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	/// c[i][cnt][sum] -> unique
	/// d[i][cnt][sum] -> any
	
	for (int i = 0; i < N; ++i) {
		cnk[i][0] = cnk[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			add (cnk[i][j], cnk[i - 1][j]);
			add (cnk[i][j], cnk[i - 1][j - 1]);
		}
	}	
	
	c[0][0][0] = c[0][1][0] = 1;
	for (int i = 0; i < N; ++i)
		d[0][i][0] = 1;	
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			for (int k = 0; k < N; ++k) {
				add (c[i][j][k], c[i - 1][j][k]);
				if (k >= i && j >= 1)
					add (c[i][j][k], (c[i - 1][j - 1][k - i] * 1ll * cnk[j][1]) % bpr);
			}
		}
	}
		
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			for (int k = 0; k < N; ++k) {
				for (int cnt = 0, l = 0; l <= k && cnt <= j; l += i, ++cnt)
					add (d[i][j][k], (d[i - 1][j - cnt][k - l] * 1ll * cnk[j][cnt]) % bpr);
			}
		}
	}
	
	int t;

	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k >= 45) {
			cout << 0 << "\n";
			continue;
		}
		int ans = 0;
		int x = n - (k - 1);
		for (int i = 0; i <= n; ++i)
			add (ans, (c[x][k][i] * 1ll * d[x][k + 1][x - i]) % bpr);
		cout << ans << "\n";
	}


	return 0;
}