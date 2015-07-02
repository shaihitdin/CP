#include <bits/stdc++.h>


using namespace std;

const int N = 1e6 + 1;

int a[N];

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int t;
	scanf ("%d", &t);

	while (t--) {
		int n;
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf ("%d", &a[i]);
		sort (a + 1, a + n + 1);

		int mx = 0, mn = 0;
		for (int i = 1; i <= n; ++i) {
		    int len = 2;
			for (; i + len - 1 <= n && a[i + len - 1] == a[i + len - 2] + 1; ++len);
			--len;
			mn += ((len / 3) + (len % 3 != 0));
			mx += ((len / 2) + (len % 2 != 0));
			i += len - 1;
		}
		printf ("%d %d\n", mn, mx);
	}

	return 0;
}
