#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int N = 1024;
bool u[N];
int t, n, k, x;
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &t);
	++t;
	while (--t) {
		scanf ("%d%d", &n, &k);
		memset (u, 0, sizeof(u) );
		u[0] = 1;
		for (int i = 1; i <= n; ++i) {
			scanf ("%d", &x);
			for (int j = 0; j < N; ++j)
				u[j ^ x] |=	u[j];
		}
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			ans = max (ans, (i ^ k) * u[i]);
		}
		printf ("%d\n", ans);
	}
	return 0;
}