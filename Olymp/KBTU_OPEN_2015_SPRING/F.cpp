#include <bits/stdc++.h>

using namespace std;

const int bN = 1e8 + 50, N = 1e6 + 100;

bitset <bN> u;

int n, a[N], ans[N];

int main () {
/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
*/
	scanf ("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf ("%d", &a[i]);

	for (int i = 1; i <= n; ++i)
		ans[i] = bN;
	
	u[0] = u[1] = 1;

	for (int i = 4; i < bN; i += 2)
		u[i] = 1;

	for (int i = 3; i * i < bN; i += 2)
		if (!u[i])
			for (int j = i * i; j < bN; j += (i + i))
				u[j] = 1;

	/*
	for (int i = 1; i <= n; ++i)
		old_a[i] = a[i];
	
	sort (a + 1, a + n + 1);

	*/

	for (int i = 1; i <= n; ++i) {
		int l_p1 = a[i], l_p2 = a[i];
		while (l_p1 > 0 && u[l_p1]) --l_p1;
		while (l_p1 < bN && u[l_p2]) ++l_p2;
		if (l_p1 >= 2)
			ans[i] = abs (a[i] - l_p1);
		if (l_p2 < bN)
			ans[i] = min (ans[i], abs (a[i] - l_p2));
	}

	for (int i = 1; i <= n; ++i)
		printf ("%d\n", ans[i]);
	
	return 0;

}