/*
ID: shaihit1
PROG: agrinet
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 101, inf = 1e9;

int n, a[N][N], ans, d[N];
bool u[N];

int main() {
	
	freopen ("agrinet.in", "r", stdin);
	freopen ("agrinet.out", "w", stdout);

	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf ("%d", &a[i][j]);
	for (int i = 2; i <= n; ++i)
		d[i] = inf;
	d[1] = 0;
	for (int step = n; step; --step) {
		int v = 0;
		for (int i = 1; i <= n; ++i)
			if (!u[i] && (!v || d[v] > d[i]))
				v = i;
		if (!v)
			break;
		u[v] = 1;
		for (int i = 1; i <= n; ++i)
			if (!u[i] && d[i] > a[v][i])
				d[i] = a[v][i];
	}
	
	for (int i = 1; i <= n; ++i)
		ans += d[i];

	printf ("%d\n", ans);
	return 0;
}
