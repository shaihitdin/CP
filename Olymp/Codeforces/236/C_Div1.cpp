#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

bitset <N> a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n;

	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int x;
			scanf ("%d", &x);
			a[i][j] = x > 0;
		}
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			if (a[i][k])
				a[i] |= a[k];
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i][j] == 0) {
				printf ("NO");
				return 0;
			}
		}
	}
	
	
	printf ("YES");

	return 0;
}