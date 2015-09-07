#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

const int bpr = 1e9 + 7;

const int N = 1e5 + 100;

ll f[N];

inline ll bin_pow (const ll &a, const ll &b) {
	if (!b)
		return 1;
	if (b & 1)
		return (a * bin_pow (a, b - 1)) % bpr;
	ll c = bin_pow (a, b / 2);
	return (c * c) % bpr;
}

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	f[0] = 1;

	for (int i = 1; i < N; ++i)
		f[i] = (f[i - 1] * i) % bpr;
	
	
	ll n;

	cin >> n;
	--n;

	ll ans = f[2 * n + 1];

	ans *= bin_pow (f[n + 1], bpr - 2);
	ans %= bpr;
	ans *= bin_pow (f[n], bpr - 2);
	ans %= bpr;

	cout << ans;

	return 0;
}