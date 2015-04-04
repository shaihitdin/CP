#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 1;

ll d[N];
double ans;
int n, k;

inline void smax (double &x, double &&y) {
	if (x < y)
		x = y;
}

inline void smax1 (ll &x, ll &&y) {
	if (x < y)
		x = y;
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d%d", &n, &k);
	int x;
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &x);
		d[i] = d[i - 1] + x;
	}
	
	int mn_len = max (k, n - 1500), mx_len = min (k + 1500, n);
	ll mx = -1;

	for (int len = k; len <= mx_len; ++len) {
		mx = -1;
		for (int i = len; i <= n; ++i)
			smax1 (mx, d[i] - d[i - len]);
		smax (ans, double (mx / (double) len));
	}

	for (int len = n; len >= mn_len; --len) {
		mx = -1;
		for (int i = len; i <= n; ++i)
			smax1 (mx, d[i] - d[i - len]);
		smax (ans, double (mx / (double) len));
	}
	
	fprintf (stderr, "%d", clock() * 1000 / CLOCKS_PER_SEC);

	printf ("%.4lf", ans);
	return 0;
}