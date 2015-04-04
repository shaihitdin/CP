/*
ID: shaihit1
PROG: numtri
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

int n, d[N][N], a[N][N];

inline int max_sum (const int &i, const int &j) {
	if (d[i][j] != -1)
		return d[i][j];
	if (i == n)
		return d[i][j] = a[i][j];
	return d[i][j] = max (max_sum (i + 1, j), max_sum (i + 1, j + 1)) + a[i][j];
}

int main() {
	
	freopen ("numtri.in", "r", stdin);
	freopen ("numtri.out", "w", stdout);

	scanf ("%d", &n);

	memset (d, -1, sizeof (d));

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			scanf ("%d", &a[i][j]);

	printf ("%d\n", max_sum (1, 1));
	return 0;
}
