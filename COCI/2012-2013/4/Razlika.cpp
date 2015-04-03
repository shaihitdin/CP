#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1, sz = 1 << 20, inf = 1e9;
int n, k, a[N], ans = inf;

#define mkp make_pair
#define F first
#define S second

set <pair <int, int> > s1;

int t[sz + N];

inline void upd (int v, const int &e) {
	v += sz;
	t[v] = e;
	v >>= 1;
	while (v)
		t[v] = min (t[v << 1], t[(v << 1) + 1]), v >>= 1;
}

int main () {
	
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);
	sort (a + 1, a + n + 1);	
	int m = n - k;
	for (int i = 1; i < sz + N; ++i)
		t[i] = inf;
	for (int i = 2; i <= m; ++i)
		upd (i - 1, a[i] - a[i - 1]);
	for (int i = m; i <= n; ++i) {
		ans = min (ans, a[i] - a[i - m + 1] + t[1]);
		upd (i - m + 1, inf);
		upd (i, a[i + 1] - a[i]);
	}
	if (clock() * 1000 / CLOCKS_PER_SEC > 500)
		exit (45);
	printf ("%d", ans);
	return 0;
}