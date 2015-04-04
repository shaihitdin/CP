#include <bits/stdc++.h>

using namespace std;

const int N = 21, inf = 1e9;

int n, m, x, y;

int d[1 << N], d1[1 << N];

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

inline int bits (const int &z) {
	int res = 0;
	for (int i = 0; i < n; ++i)
		res += bit (z, i);
	return res;
}             

int g[N];

int main () {

	freopen ("headmasters.in", "r", stdin);
	freopen ("headmasters.out", "w", stdout);

	scanf ("%d%d", &n, &m);

	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d", &x, &y);
		--x;
		--y;
		g[x] |= (1 << y);
		g[y] |= (1 << x);
	}

	for (int i = 1; i < (1 << n); ++i)
		d[i] = inf;
	d[0] = 0;
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (bit (i, j))
				continue;
			d1[i | (1 << j)] = d1[i] - bits (i & g[j]) + bits (g[j] & (~i));
			d[i | (1 << j)] = min (d[i | (1 << j)], d[i] + d1[i | (1 << j)]);
		}
	}
	printf ("%d", d[(1 << n) - 1]);
	
	return 0;
}