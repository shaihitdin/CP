#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100, bpr = 1e9 + 7;

typedef long long ll;

inline ll bin_pow (const ll &a, const ll &b) {
	if (!b)
		return 1;
	if (b & 1)
		return (a * bin_pow (a, b - 1)) % bpr;
	ll c = bin_pow (a, b / 2);
	return (c * c) % bpr;
}

set <int> Set;

ll f[N];

inline ll cnk (const ll &n, const ll &k) {
	if (n < k)
		return 0;
	ll x = f[n];
	x = (x * bin_pow (f[k], bpr - 2)) % bpr;
	x = (x * bin_pow (f[n - k], bpr - 2)) % bpr;
	return x;
}

int n, m, k, cc;

int main () {

	freopen ("dress.in", "r", stdin);
	freopen ("dress.out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		Set.insert (x);
	}

	for (int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		if (Set.find (x) != Set.end ())
			++cc;
	}
	
	f[0] = 1;
	
	for (int i = 1; i < N; ++i)
		f[i] = (f[i - 1] * 1ll * i) % bpr;
	
	ll ans = 0;
	
	for (int i = 0; i <= min (cc, k); ++i) {
		ll res = cnk (n - i, k - i);
		res = (res * cnk (m - i, k - i)) % bpr;
		res = (res * cnk (cc, i)) % bpr;
		if (i & 1) {
			ans -= res;
		} else {
			ans += res;
		}
		ans %= bpr;
		ans += bpr;
		ans %= bpr;
	}	
	
	cout << ans;
	
	return 0;
}