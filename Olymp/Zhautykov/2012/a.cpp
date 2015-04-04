#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;
const int N = 800001, sz = 1 << 20, inf = 1e9;
set <int> le;
int pos[N];
int n, m, x;
int t[1 << 22];
int get (int l, int r) {
	l += sz;
	r += sz;
	int res = -inf;
	while (l <= r) {
		if (l & 1) {
			res = max (res, t[l]);
			++l;
		}
		if (!(r & 1)) {
			res = max (res, t[r]);
			--r;
		}
		l >>= 1;
		r >>= 1;
	}
	return res;
}
void upd (int x, const int &to) {
	x += sz;
	t[x] = to;
	for (x >>= 1; x > 0; x >>= 1)
		t[x] = max (t[x << 1], t[(x << 1) + 1]);
	return;
}
int un;
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	for (int i = 1; i < (1 << 22); ++i)	t[i] = -inf;
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &x);
		int y = get (1, x - 1);
		if (y == -inf) {
			pos[x] = ++un;			
		}
		else {
			pos[x] = pos[y];
			upd (y, -inf);			
		}
		printf ("%d ", pos[x]);
		upd (x, x);
	}
	puts("");
	for (int i = 1; i <= n; ++i)
		printf ("%d ", pos[i]);
	return 0;
}