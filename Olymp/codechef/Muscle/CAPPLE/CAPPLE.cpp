#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N = 100001;
unsigned short t, n, a[N];
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%hu", &t);
	++t;
	while (--t) {
		scanf ("%hu", &n);
		for (int i = 1; i <= n; ++i) {
			scanf ("%hu", &a[i]);
		}
		sort (a + 1, a + n + 1);
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			if (a[i] != a[i - 1])
				++cnt;
		printf ("%hu\n", cnt);
	}
	return 0;
}