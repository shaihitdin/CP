#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e6 + 100, bpr = 1e9 + 7;

int lp[N];

inline int bin_pow (int a, int b) {
	if (!b)
		return 1;
	if (b & 1)
		return (bin_pow (a, b - 1) * 1ll * a) % bpr;
	int c = bin_pow (a, b / 2);
	return (c * 1ll * c) % bpr;
}


inline int cnk (int n, int k) {
	int k1, k2;
	k1 = k;
	k2 = n - k;
	int res = 1;
	for (int i = k2 + 1; i <= n; ++i)
		res = (res * 1ll * i) % bpr;
	int res2 = 1;
	for (int i = 1; i <= k1; ++i)
		res2 = (res2 * 1ll * i) % bpr;
	res = (res * 1ll * bin_pow (res2, bpr - 2)) % bpr;
	return res;
}

int f_dp[35][35];
int dp[35];

int main () {
	#ifdef Geodsso
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	for (int i = 2; i < N; ++i)
		if (!lp[i])
			for (int j = i; j < N; j += i)
				if (!lp[j])
					lp[j] = i;
	
	f_dp[0][0] = 1; // i -> member cnt, j -> item cnt

	for (int i = 1; i <= 30; ++i)
		for (int j = 1; j <= 30; ++j)
			for (int k = 0; k <= j; ++k)
				f_dp[i][j] = (f_dp[i][j] + f_dp[i - 1][j - k]) % bpr;
	
	int t;

	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		if (n == 1) {
			cout << 1 << "\n";
			continue;
		}
		int cnt = 0;
		vector <int> dc;
		while (n > 1) {
			int z = lp[n];
			int cnt = 0;
			while (lp[n] == z) {
				++cnt;
				n /= lp[n];
			}
			dc.emplace_back (cnt);
		}
		memset (dp, 0, sizeof (dp));
		dp[0] = 1;
		for (int j = 1; j <= dc.size (); ++j) {
			dp[j] = (dp[j - 1] * 1ll * f_dp[dc.size ()][dc[j - 1]]) % bpr;
		}			
		cout << dp[dc.size ()] << "\n";
	}

	return 0;
}