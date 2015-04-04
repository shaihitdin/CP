/*
ID: shaihit1
PROG: inflate
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 1;

int n, m, c[N], w[N], d[N], ans;

int main() {
	
	freopen ("inflate.in", "r", stdin);
	freopen ("inflate.out", "w", stdout);

	scanf ("%d%d", &m, &n);

	for (int i = 1; i <= n; ++i)
		scanf ("%d%d", &c[i], &w[i]);

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j + w[i] <= m; ++j)
			d[j + w[i]] = max (d[j + w[i]], d[j] + c[i]);
	
	for (int i = 1; i <= m; ++i)
		ans = max (ans, d[i]);
	
	printf ("%d\n", ans);	
	return 0;
}
