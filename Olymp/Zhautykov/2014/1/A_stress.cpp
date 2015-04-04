#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 5001;
long long ans;
long long x[N], g[N], d[N], n, en, res;
int main () {
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	scanf ("%I64d", &n);
	for (int i = 1; i <= n; ++i)
		scanf ("%I64d%I64d%I64d", &x[i], &g[i], &d[i]);
	for (int i = 1; i <= n; ++i) {
		en = x[i] + d[i];
		res = g[i];
		ans = max (ans, res);
		for (int j = i + 1; j <= n; ++j) {
			en += d[j];
			res += g[j];
			if (en >= x[j])
				ans = max (ans, res);
		}
	}
	printf ("%I64d", ans);
	return 0;
}