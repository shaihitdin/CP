#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e6 + 100, bpr = 1e9 + 7;

ll f[N], dp[1100][1100];

inline ll bin_pow (ll a, ll b) {
	if (!b)
		return 1;
	if (b & 1)
		return (a * bin_pow (a, b - 1)) % bpr;
	ll c = bin_pow (a, b / 2);
	return (c * c) % bpr;
}

inline ll cnk (ll n, ll k) {
   	if (n < k)
		return 0;
	if (n < 0)
		return 0;
	ll res = f[n];
	res = (res * bin_pow (f[k], bpr - 2)) % bpr;
	res = (res * bin_pow (f[n - k], bpr - 2)) % bpr;
	return res;
}

inline ll ank (ll n, ll k) {
	if (n < k)
		return 0;
   	if (n < 0)
		return 0;
	ll res = f[n];
	res = (res * bin_pow (f[n - k], bpr - 2)) % bpr;
	return res;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
/*
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
*/
	ll n, m, k;

	cin >> n >> m >> k;

	if (m == 1) {
		cout << bin_pow (k, n);
		return 0;
	}
	
	f[0] = 1;

	for (int i = 1; i < N; ++i)
		f[i] = (f[i - 1] * i) % bpr;
		
	ll ans = 0;
	
	dp[0][0] = 1;

	for (int i = 1; i < 1100; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = (((dp[i - 1][j] * j) % bpr) + dp[i - 1][j - 1]) % bpr;
		}
	}
	
	for (int i = 0; i <= min (n, k); ++i) {
		ll tmp = bin_pow (i, n * (m - 2));
		for (int j = max (i, 1); j <= min (n, k); ++j) {
			if (i + (j - i) * 2 > k)
				continue;
			ll tmp1 = cnk (k, i);
			
			ll tmp2 = (cnk (k - i, j - i) * dp[n][j]) % bpr;

			tmp2 = (tmp2 * f[j]) % bpr;
			
			ll tmp3 = (cnk (k - i - (j - i), j - i) * dp[n][j]) % bpr;
			
			tmp3 = (tmp3 * f[j]) % bpr;

			tmp2 = (tmp2 * tmp3) % bpr;

			tmp2 = (tmp * tmp2) % bpr;
			
			tmp2 = (tmp1 * tmp2) % bpr;
			//cerr << "(" << i << ", " << j << ") = " << tmp1 << " " << tmp3 << "\n";
			ans = (ans + tmp2) % bpr;
		}
		//cerr << "\n";
	}
	
	cout << ans;
	
	return 0;
}