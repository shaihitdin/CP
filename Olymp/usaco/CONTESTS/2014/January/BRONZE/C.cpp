#include <iostream>
#include <assert.h>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <map>
using namespace std;
const int N = 2e2;
int a[N], b[N], c[N], d[N];
inline bool cmp (const int &x, const int &y) {
	return a[x] < a[y];
}
map <int, int> m[N];
set <int> s[N];
int ans, n;
int t[N * 16], sz = (1 << 8);

inline void upd (int x, const int &to) {
	for (x += sz, t[x] = to, x >>= 1; x; x >>= 1)
		t[x] = max (t[x << 1], t[(x << 1) + 1]);
}

inline int get (int l, int r) {
	int res = 0;
	for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			res = max (t[l], res), ++l;
		}
		if (!(r & 1)) {
			res = max (t[r], res), --r;
		}
	}
	res = max (res, t[l]);
	
	for (int i = l; i <= r; ++i)
		res = max (d[i], res);
	return res;
}

int main () {
	freopen ("recording.in", "r", stdin);
	freopen ("recording.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d", &a[i], &b[i]);
	}
	a[n + 1] = 1e9 + 1;
	b[n + 1] = 1e9 + 1;
	for (int i = 1; i <= n; ++i)
		c[i] = i;
	sort (c + 1, c + n + 2, cmp);
	for (int i = n + 1; i; --i) {
		m[i] = m[i + 1];
		s[i] = s[i + 1];
		m[i][a[i]] = i, s[i].insert (a[i]);
	}
	for (int step = n; step; --step) {
		for (int i = 0; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j) {
				int pos = m[j + 1][*s[j + 1].lower_bound (max (b[j], b[i]))];
				assert (pos != 0);
				int to_add;
				if (i != 0) {
					to_add = get (0, i - 1);
					d[pos] = max (d[pos], to_add + 2);
				}
				else {
					to_add = get (0, j - 1);
					d[pos] = max (d[pos], to_add + 1);
				}
				upd (pos, d[pos]);
			}
		for (int i = 0; i <= n + 1; ++i)
	    	cerr << d[i] << " ";
	    cerr << "\n";
	}
	
	for (int i = 0; i <= n + 1; ++i)
		ans = max (d[i], ans);
	printf ("%d", ans);	
	return 0;
}