#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 100, bpr = 1e9 + 7;

int f[N];

inline int bin_pow (const int &a, const int &b) {
	if (b == 0)
		return 1;
	if (b & 1)
		return (a * 1ll * bin_pow (a, b - 1)) % bpr;
	int c = bin_pow (a, b / 2);
	return (c * 1ll * c) % bpr;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	f[0] = 1;

	for (int i = 1; i < N; ++i)
		f[i] = (f[i - 1] * 1ll * i) % bpr;
	
	int n;
	
	cin >> n;

	++n;

	int res1 = (2 * f[2 * n - 1]) % bpr;
	res1 = (res1 * 1ll * bin_pow ((f[n] * 1ll * f[n - 1]) % bpr, bpr - 2)) % bpr;
	res1 -= 1;
	res1 %= bpr;
	res1 += bpr;
	res1 %= bpr;

	cout << res1;
	
	return 0;
}