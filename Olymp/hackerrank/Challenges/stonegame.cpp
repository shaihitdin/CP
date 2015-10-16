#include <bits/stdc++.h>

using namespace std;

const int N = 110, bpr = 1e9 + 7;

typedef long long ll;

int a[N], n;

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	sort (a + 1, a + n + 1);

	ll ans = 0;
	
	int k = n;
	while (k >= 1 && a[k] == a[n])
		--k;
	++k;
	
	ll res = 1;
	
	for (int i = 1; i < k; ++i)
		res = (res * 1ll * (a[i] + 1)) % bpr;
	
	ll val = 1;

	for (int i = k; i < n; ++i)
		val = (val * 1ll * (a[i] + 1)) % bpr;

	val = (val * 1ll * (n - k + 1)) % bpr;

	for (int i = 1; i <= n; ++i)
		--a[i];

	ll res2 = 1;
	
	for (int i = 1; i < k; ++i)
		res2 = (res2 * 1ll * (a[i] + 1)) % bpr;
	
	ll val2 = 1;

	for (int i = k; i < n; ++i)
		val2 = (val2 * 1ll * (a[i] + 1)) % bpr;

	val2 = (val2 * 1ll * (n - k + 1)) % bpr;
	

	
	res = (res * 1ll * val) % bpr;

	res2 = (res2 * 1ll * val2) % bpr;
	
	ans = res - res2;
	
	ans %= bpr;
	
	ans += 2 * bpr;

	ans %= bpr;
	
	cout << ans;
	
	return 0;
}