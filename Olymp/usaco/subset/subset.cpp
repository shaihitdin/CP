/*
ID: shaihit1
PROG: subset
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

long long d[40][781];
int n;
int main() {
	
	freopen ("subset.in", "r", stdin);
	freopen ("subset.out", "w", stdout);
	
	scanf ("%d", &n);

	d[0][0] = 1;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= 780; ++j) {
			if (!d[i][j])
				continue;
			d[i + 1][j + i + 1] += d[i][j];
			d[i + 1][j] += d[i][j];
		}
	int need = (n * (n + 1)) / 2;
	if (need & 1)
		printf ("0\n");
	else
		printf ("%lld\n", d[n][need >> 1] >> 1); 
	return 0;
}
