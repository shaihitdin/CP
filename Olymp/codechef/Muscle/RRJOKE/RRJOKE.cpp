#include <iostream>
#include <stdio.h>
using namespace std;
int t;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &t);
	++t;
	while (--t) {
		int n;
		scanf ("%d", &n);
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			scanf ("%*d%*d");
			ans ^= i;
		}
		printf ("%d\n", ans);
	}
	return 0;
}