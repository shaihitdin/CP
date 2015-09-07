#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 100;

typedef long long ll;

ll n, a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	scanf ("%I64d", &n);

	for (int i = 1; i <= n; ++i)
		scanf ("%I64d", &a[i]);

	sort (a + 1, a + n + 1);
	
	ll l = -1, r = 1e4;

	while (r - l > 1) {
		ll mid = (r + l) >> 1;
		bool flag = 0;
		for (ll diff = 0; diff <= 2e4; ++diff) {
			ll l1 = a[1] - mid, r1 = a[1] + mid;
			for (int i = 2; i <= n && l1 <= r1; ++i) {
				ll l2 = a[i] - mid - (i - 1) * diff, r2 = a[i] + mid - (i - 1) * diff;
				l1 = max (l1, l2);
				r1 = min (r1, r2);
			}
			if (l1 <= r1) {
				flag = 1;
				break;
			}
		}
		if (flag)
			r = mid;
		else
			l = mid;
	}
	
	for (ll diff = 0; diff <= 2e4; ++diff) {
		ll l1 = a[1] - r, r1 = a[1] + r;
		for (int i = 2; i <= n && l1 <= r1; ++i) {
			ll l2 = a[i] - r - (i - 1) * diff, r2 = a[i] + r - (i - 1) * diff;
			l1 = max (l1, l2);
			r1 = min (r1, r2);
		}
		if (l1 <= r1) {
			printf ("%I64d\n%I64d %I64d", r, l1, diff);
			return 0;
		}
	}
	
	assert (0);
	
	return 0;
}