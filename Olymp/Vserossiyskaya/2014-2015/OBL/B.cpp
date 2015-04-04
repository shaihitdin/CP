#include <bits/stdc++.h>

using namespace std;
const int N = 100001, sz = (1 << 17);
int n, m;
int a[N];
long long d[N], t[sz * 2];
long long ans = 1e18;
inline void upd (int x, const long long &to) {
	for (x += sz, t[x] = to, x >>= 1; x; x >>= 1)
		t[x] = max (t[x << 1], t[(x << 1) + 1]);
}

inline long long get (int l, int r) {
	long long res = -1;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)	res = max (res, t[l]), ++l;
		if (!(r & 1))	res = max (res, t[r]), --r;
		if (l > r)	break;
	}
	return res;
}

int main () {
	freopen ("prizes.in", "r", stdin);
	freopen ("prizes.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		if (i <= m)	d[m] += a[i];
		else	d[i] = d[i - 1] + a[i] - a[i - m];
		upd (i, d[i]);
	}
	for (int i = m; i <= n; ++i) {
		int l1 = m, r1 = i - m, l2 = i + m, r2 = n;
		if (l1 <= r1 && l2 <= r2) {
			ans = min (ans, max (get (l1, r1), get (l2, r2)));
		}
		else if (l1 <= r1) {
			//cerr << i << " " << l1 << " " << r1 << " " << get (l1, r1) << "\n";
			ans = min (ans, get (l1, r1));
		}
		else if (l2 <= r2) {
			//cerr << i << " " << l2 << " " << r2 << " " << get (l2, r2) << "\n";
			ans = min (ans, get (l2, r2));
		}
	}
	printf ("%I64d", ans);
	return 0;
}