#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

int a[N], n;

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	scanf ("%d", &n);

	double sum = 0;
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
		sum += a[i];
	}
	sum /= n;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += (a[i] > sum);
	}
	
	printf ("%d", ans);
	
	return 0;
}