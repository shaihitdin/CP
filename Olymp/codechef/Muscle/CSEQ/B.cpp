#include <bits/stdc++.h>
 
using namespace std;
 
const int bpr = 1e6 + 3, N = 1e6 + 10;
 
int f[N], rf[N];
 
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


inline int cnk (const int &n, const int &k) {
	return (((f[n] * 1ll * rf[k]) % bpr) * 1ll * rf[n - k]) % bpr;
}
 
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
 
 
	f[0] = 1;
	rf[0] = 1;
 
	for (register int i = 1; i < N; ++i) {
		f[i] = (f[i - 1] * 1ll * i) % bpr;
		rf[i] = bin_pow (f[i], bpr - 2);
	}
 
	register int t;	
	scanf ("%d", &t);
	register int n, l, r;
	register int k (r - l), ans (0);	
	for (; t; --t) {
		scanf ("%d%d%d", &n, &l, &r);
		k = r - l, ans = 0;
		register int k1 = (n + k) / bpr, k2 = (n - 1) / bpr, k3 = k / bpr;
		if (k1 == k2 + k3)
			for (register int i = 1; i <= n && cnk (i + k, i); ++i)
				ans = (ans + cnk (i + k, i)) % bpr;
		else
			ans = 0;
		printf ("%d\n", ans);
	}
 
	#ifndef ONLINE_JUDGE
	fprintf (stderr, "%d", clock () * 1000 / CLOCKS_PER_SEC);
	#endif
	
	return 0;
}