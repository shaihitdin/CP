#include <bits/stdc++.h>

using namespace std;

const int bpr = 1e6 + 3;

int f[bpr], rf[bpr];

inline int bin_pow (const int &x, const int &y) {
	if (!y)
		return 1;
	if (y & 1)
		return (x * 1ll * bin_pow (x, y - 1)) % bpr;
	int b = bin_pow (x, y >> 1);
	return (b * 1ll * b) % bpr;
}

inline int factmod (const int &n) {
	if (n <= 1)
		return 1;
	int res = (1ll * (((n / bpr) & 1) ? bpr - 1 : 1)) % bpr;
	res = (res * 1ll * f[n % bpr]) % bpr;
	return (res * 1ll * factmod (n / bpr)) % bpr;
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	f[0] = 1;
	
	for (register int i = 1; i < N; ++i) {
		f[i] = (f[i - 1] * 1ll * i) % bpr;
	}

	register int t;	
	scanf ("%d", &t);
	register int n, l, r;
	register int k, ans (0);	
	for (; t; --t) {
		scanf ("%d%d%d", &n, &l, &r);
		k = r - l;
		register int k1 = (n + k) / bpr, k2 = (n - 1) / bpr, k3 = k / bpr;
		if (k1 == k2 + k3)
			printf ("%d\n", int ((((factmod (n + k) * 1ll * bin_pow (factmod (n - 1), bpr - 2)) % bpr) * 1ll * bin_pow (factmod (k), bpr - 2)) % bpr));
		else
			printf ("0\n");
	}

	#ifndef ONLINE_JUDGE
	fprintf (stderr, "%d", clock () * 1000 / CLOCKS_PER_SEC);
	#endif
	
	return 0;
}