#include <iostream>
#include <stdio.h>
using namespace std;
int n, k, l[51], r[51], ans, now;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d", &l[i], &r[i]);
	}
	now = 1;
	for (int i = 1; i <= n; ++i) {
		ans += ((l[i] - now) % k);
		ans += (r[i] - l[i] + 1);
		now = r[i] + 1;
	}
	printf ("%d", ans);
	return 0;
}