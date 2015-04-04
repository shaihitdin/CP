#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 2;
int t, n, k, a[N];
inline ll pref_sum (const ll &num) {
	return (num * (num + 1)) >> 1;
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	scanf ("%d", &t);
	for (int test = 1; test <= t; ++test) {
		scanf ("%d%d", &n, &k);
		for (int i = 1; i <= k; ++i)
			scanf ("%d", &a[i]);
		sort (a + 1, a + k + 1);
		a[k + 1] = n + 1;
		ll can = 0;
		int i = 1;
		for (; i <= k + 1; ++i) {
			can += (pref_sum (a[i] - 1) - pref_sum (a[i - 1]));
			if (can < a[i]) {
				break;
			}
		}
		if ((can + 1) & 1)
			puts ("Chef");
		else
			puts ("Mom");
	}
	return 0;
}