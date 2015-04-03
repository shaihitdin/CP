#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
ll n, m, a[300001], l, r, mid;
bool calc (const ll &g) {
	long long num = 0;
	for (int i = 1; i <= m; ++i) {
		num += ((a[i] / g) + ((a[i] % g) != 0));
	}
	return num <= n;
}
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%I64d%I64d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf ("%I64d", &a[i]);
	}
	l = 0;
	r = (1e9) + 1;
	while (r - l > 1) {
		mid = (r + l) / 2;
		if (calc(mid))
			r = mid;		
		else
			l = mid;
	}
	printf ("%I64d", r);
	return 0;
}