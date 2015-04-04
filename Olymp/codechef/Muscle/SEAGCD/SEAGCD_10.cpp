#include <iostream>
#include <stdio.h>
using namespace std;
int ans[11], r_ans, n, m, l, r, t, a[11];
inline int gcd (int x, int y) {
	if (y == 0)
		return x;
	return gcd (y, x % y);
}
inline void rec (int v, int le) {
	if (v == n + 1) {
		int now = a[1];
		for (int i = 2; i <= n; ++i) {
			now = gcd (now, a[i]);
		}		
		++ans[now];
		return;	
	}
	for (int i = 1; i <= le; ++i) {
		a[v] = i;
		rec (v + 1, le);
	}
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &t);
	for (int test = 0; test < t; ++test) {
		scanf ("%d%d%d%d", &n, &m, &l, &r);
		
		for (int i = 1; i <= m; ++i)
			ans[i] = 0;
		for (int i = l; i <= r; ++i) {
		    rec (1, m / i);
		}
		for (int i = 1; i <= m; ++i) {
			cerr << ans[i] << " ";
		}
		cerr << "\n";
		//printf ("%d\n", ans);
	}
	return 0;
}