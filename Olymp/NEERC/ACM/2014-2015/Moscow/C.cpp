#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define left can

ll a, b, c;

inline ll bin (const ll &mid1) {
	ll l2 = 0, r2 = 1e9 + 100;
	while (r2 - l2 > 1) {
		ll mid2 = (r2 + l2) >> 1;
		ll cnt_per_c = mid1 / mid2;
		ll filled = min (b, cnt_per_c * a);
		ll now = filled * mid2;
		ll cnt = mid1 % mid2;
		ll fills = min (b - filled, a);
		now += cnt * fills;
		if (now >= c)
			r2 = mid2;
		else
			l2 = mid2;
	}
	return r2;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif


	cin >> a >> b >> c;

	ll l1 = 0, r1 = 1e9 + 100;
	while (r1 - l1 > 1) {
		ll mid1 = (r1 + l1) >> 1;
		if (bin (mid1) == 1e9 + 100)
			l1 = mid1;
		else
			r1 = mid1;
	}

	cout << r1 << " " << bin (r1);
	
	return 0;
}