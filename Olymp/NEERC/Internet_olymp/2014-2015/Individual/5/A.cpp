#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

bool c[N];
int n, m, here;

int main () {
	freopen ("swap.in", "r", stdin);
	freopen ("swap.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
		c[i] = 1;
	scanf ("%d", &m);
	here = n;
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf ("%d%d", &x, &y);
		if (c[x] == c[y] || (x > n && y > n) || (x <= n && y <= n))
			goto print;
		if (x > y)
			swap (x, y);
		if (c[x] == 1)
			--here;
		else
			++here;
		print:;
		swap (c[x], c[y]);
		printf ("%d\n", here);
	}
	return 0;
}