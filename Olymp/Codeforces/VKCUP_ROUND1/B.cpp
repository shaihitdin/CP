#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

typedef long long ll;

ll d[N];
ll x, y, n;

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%I64d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%I64d%I64d", &x, &y);				
		if (x > y)
			swap (x, y);
		for (int j = 1; j < x; ++j)
			d[j] = 1e12;
		for (int j = x; j < y; ++j)
			d[j] += y;
		for (int j = y; j < N; ++j)
			d[j] += x;
	}
	ll ans = 1e9;
	for (int i = 1; i < N; ++i)
		if (d[i])
			ans = min (ans, d[i] * i);
	printf ("%I64d", ans);
	return 0;
}