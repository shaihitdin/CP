#include <bits/stdc++.h>

using namespace std;

inline void calc () {

}

int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 1; i <= k; ++i) {
		scanf ("%d%d", &x[i], &y[i]);
		v[x[i]].push_back (y[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d%d%d", &sx[i], &sy[i], &fx[i], &fy[i]);
		g[fx[i]].push_back (mkp (sx[i], mkp (sy[i], fy[i])));
	}

	calc ();
	return 0;
}