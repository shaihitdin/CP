#include <bits/stdc++.h>

using namespace std;

int n;

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	int l1 = -1e9, r1 = 1e9, l2, r2;
	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i) {
		int x;
		scanf ("%d", &x);
		r1 = min (r1, x);
		l2 = x + x - r1;
		r2 = x + x - l1;
		l1 = l2;
		r1 = r2;
	}

	printf ("%d\n", max (0, r2 - l2 + 1));
	
	return 0;
}