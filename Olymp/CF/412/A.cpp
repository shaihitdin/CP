#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> t;

	while (t--) {
		ll x, y, p, q;
		cin >> x >> y >> p >> q;
		if (p == 0) {
			if (x == 0) {
				cout << 0 << "\n";
			} else {
				cout << -1 << "\n";
			}
			continue;
		}
		if (q == 1) {
			if (x == y) {
				cout << 0 << "\n";
			} else {
				cout << -1 << "\n";
			}
			continue;
		}
		ll ans = 0;
		ans += p - (x % p);
		x += ans;
		ans += q - (y % q);
		y += ans;
		ll gg = __gcd (x, y);
		x /= gg;
		y /= gg;
		if (x >= p * (y / q)) {
			ll c = x / p;
			ans += q * c - (x % (q * c));
			cout << ans << "\n";
		} else {

		}
	}

	return 0;
}