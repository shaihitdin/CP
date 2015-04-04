#include <iostream>
#include <stdio.h>
using namespace std;
const int N = (1e5) + 1;
long long t, n, q, a[N], d_p[N], d_s[N], l, r;
inline int gcd (const int &x, const int &y) {
	return y ? gcd (y, x % y) : x;
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%I64d", &t);
	for (int test = 1; test <= t; ++test) {
		scanf ("%I64d%I64d", &n, &q);
		for (int i = 1; i <= n; ++i)
			scanf ("%d", &a[i]);
		d_p[1] = a[1];
		for (int i = 2; i <= n; ++i)
			d_p[i] = gcd (d_p[i - 1], a[i]);
		d_s[n] = a[n];
		for (int i = n - 1; i >= 1; --i)
			d_s[i] = gcd (d_s[i + 1], a[i]);
		for (int i = 1; i <= q; ++i) {
			scanf ("%d%d", &l, &r);
			if (l == 1) {
				printf ("%d\n", d_s[r + 1]);
				continue;
			}
			if (r == n) {
				printf ("%d\n", d_p[l - 1]);
				continue;
			}
			printf ("%d\n", gcd(d_p[l - 1], d_s[r + 1]));
		}
	}
	return 0;
}