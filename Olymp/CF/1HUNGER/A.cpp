#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll l, r, p, q;

inline ll entries (const ll &l, const ll &r, const ll &a) {
	return r / a - (l - 1) / a;
}

inline bool exceed (const ll &a, const ll &b, const ll &limit) {
	return (a * 1.0 * b) > (1.0 * limit);
}

inline ll gcd (const ll &a, const ll &b) {
	return b ? gcd (b, a % b) : a;
}

inline ll lcm (const ll &a, const ll &b) {
	return a / gcd (a, b) * b;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> l >> r >> p >> q;

	ll ans = 0;
	
	ll prevq1 = 1;
	
	for (ll pw = 1, p1 = p, q1 = q; p1 <= r; ++pw) {
		if (pw > 1) {
			ans -= entries (l, r, p1);
			if (prevq1 != r + 1 && !exceed (p1 / gcd (p1, prevq1), prevq1, r))
				ans += entries (l, r, lcm (p1, prevq1));
		}

		ans += entries (l, r, p1);

		if (!exceed (p1 / gcd (p1, q1), q1, r))
			ans -= entries (l, r, lcm (p1, q1));
		
		prevq1 = q1;
		
		if (exceed (q1, q, r))
			q1 = r + 1;
		else
			q1 *= q;
		
		if (exceed (p1, p, r))
			break;
		else
			p1 *= p;
	}
	
	cout << ans;
	
	return 0;
}