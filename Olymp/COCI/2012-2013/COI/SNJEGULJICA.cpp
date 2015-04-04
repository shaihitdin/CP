#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int sz = (1 << 18), N = (2e5) + 1;
int n, m;
int t_mx[sz << 1], t_mn[sz << 1];
int a[N];
inline void upd (int x, const int &to) {
	for (x += sz, t_mx[x] = to, t_mn[x] = to, x >>= 1; x; x >>= 1)
		t_mx[x] = max (t_mx[x << 1], t_mx[(x << 1) + 1]), t_mn[x] = min (t_mn[x << 1], t_mn[(x << 1) + 1]);
}

inline int get_mn (int l, int r) {
	int res = 1e9;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)	res = min (res, t_mn[l]), ++l;
		if (!(r & 1))	res = min (res, t_mn[r]), --r;
	}
	return res;
}

inline int get_mx (int l, int r) {
	int res = -1;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)	res = max (res, t_mx[l]), ++l;
		if (!(r & 1))	res = max (res, t_mx[r]), --r;
	}
	return res;
}

int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	for (int i = 1; i < (sz << 1); ++i)
		t_mn[i] = (int)1e9;
	for (int i = 1; i <= n; ++i)
		t_mx[a[i] + sz] = t_mn[a[i] + sz] = i;
	for (int i = sz - 1; i; --i)
		t_mx[i] = max (t_mx[i << 1], t_mx[(i << 1) + 1]), t_mn[i] = min (t_mn[i << 1], t_mn[(i << 1) + 1]);
	for (int i = 1; i <= m; ++i) {
		int q, l, r;
		scanf ("%d%d%d", &q, &l, &r);
		if (q == 1) {
			int temp1 = t_mn[sz + a[l]],
			temp2 = t_mn[sz + a[r]];
			upd (a[l], temp2);
			upd (a[r], temp1);
			swap (a[l], a[r]);
		} else {
			int mx = get_mx (l, r);
			 
			if (mx - mn == r - l)
				puts ("YES");
			else
				puts ("NO");
		}
	}
	return 0;
}