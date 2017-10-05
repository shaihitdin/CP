#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = 1e5 + 100, bpr = 1e9 + 7;

int a[N];


inline int bin_pow (int x, int y) {
	if (!y)
		return 1;
	if (y & 1)
		return bin_pow (x, y - 1) * x % bpr;
	int c = bin_pow (x, y / 2);
	return c * c % bpr;
}

main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	int n;
	cin >> n;
	int ans = 0;
	ans = bin_pow (7, n);
	ans = bin_pow(3, 3 * n) - ans + bpr;
	ans %= bpr;
	cout << ans;
	return 0;
}