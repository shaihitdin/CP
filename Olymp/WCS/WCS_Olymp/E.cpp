#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int oo = 1e9, bpr = 1e9 + 7;

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

int n, m;
int c[20][20];
int calc[20][1 << 18];
int dp[1 << 20];
int pw[1 << 20];

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	if (n == 1) {
		cout << 1;
		return 0;
	}
	
	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		++c[x][y];
		++c[y][x];
	}
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < (1 << n); ++j)
			for (int k = 0; k < n; ++k)
				if (bit (j, k))
					calc[i][j] += c[i][k];
	
	pw[0] = 1;

	for (int i = 1; i < (1 << 20); ++i) {
		add (pw[i], pw[i - 1]);
		add (pw[i], pw[i - 1]);
	}
/*	
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (c[i][j])
				add (dp[(1 << i) | (1 << j)], pw[c[i][j]] - 1);
		}
	}
*/	
	for (int i = 0; i < n; ++i)
		dp[1 << i] = 1;
	for (int i = 0; i < n; ++i) {
		for (int mask = 0; mask < (1 << n); ++mask) {			
			if (!bit (mask, i))
				add (dp[mask | (1 << i)], ((pw[calc[i][mask]] - 1) * 1ll * dp[mask]) % bpr);
		}
		cerr << dp[(1 << n) - 1] << "\n";
	}
	for (int i = 0; i < (1 << n); ++i) {
		cerr << ((bitset <3>) (i)) << " " << dp[i] << "\n";
	}
	
	cout << dp[(1 << n) - 1];
	
	return 0;
}