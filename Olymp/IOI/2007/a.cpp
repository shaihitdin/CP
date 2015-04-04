#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define y0 ahaha

ll n, x0, y0;

inline bool inside (const ll &x, const ll &y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

string q_ans;


inline bool check_poll (const ll &x, const ll &y) {
	cout << "examine " << x << " " << y << "\n";
	cout.flush();
	cin >> q_ans;
	return (q_ans == "true") ? 1 : 0;
}

inline bool check_it (const ll &x, const ll &y, const ll &xdiff, const ll &ydiff, const ll &sign) {	
	for (ll i = 1; i <= 4; ++i)
		if (!check_poll (x + sign * (max (xdiff / i, 1ll) - 1), y + sign * (max (ydiff / i, 1ll) - 1)))
			return 0;
	return 1;
}

int main () {
	/*
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	*/

	cin >> n >> x0 >> y0;

	ll l = 1, r = (n + 1) / 3;

	while (r - l > 1) {
		ll mid = (r + l) >> 1LL;
		if (inside (x0 - mid + 1, y0)) {
			if (check_it (x0, y0, mid, 0, -1))
				l = mid;
			else
				r = mid;
		}
		else
			r = mid;
	}

	ll lx = x0 - l + 1;


	l = 1;
	r = (n + 1) / 3;

	while (r - l > 1) {
		ll mid = (r + l) >> 1LL;
		if (inside (x0 + mid - 1, y0)) {
			if (check_it (x0, y0, mid, 0, 1))
				l = mid;
			else
				r = mid;
		}
		else
			r = mid;
	}
	ll rx = x0 + l - 1;

	l = 1, r = (n + 1) / 3;

	while (r - l > 1) {
		ll mid = (r + l) >> 1LL;
		if (inside (x0, y0 - mid + 1)) {
			if (check_it (x0, y0, 0, mid, -1))
				l = mid;
			else
				r = mid;
		}
		else
			r = mid;
	}

	ll ly = y0 - l + 1;


	l = 1;
	r = (n + 1) / 3;
	while (r - l > 1) {
		ll mid = (r + l) >> 1LL;
		if (inside (x0, y0 + mid - 1)) {
			if (check_it (x0, y0, 0, mid, 1))
				l = mid;
			else
				r = mid;
		}
		else
			r = mid;
	}
	ll ry = y0 + l - 1;

	ll x = lx, y = ly, m = rx - lx + 1;

	//assert (check_poll (x, y));

	//cout << "solution " << x << " " << y << "\n";
	
	while (x - m > 0 && y - m > 0) {
		ll nx, ny;
		nx = x - m;
		ny = y - m;
		if (check_poll (nx, ny))
			x = nx, y = ny;
		else
			break;
	}
	while (x - (2 * m) > 0) {
		ll nx, ny;
		nx = x - (2 * m);
		ny = y;
		if (check_poll (nx, ny))
			x = nx, y = ny;
		else
			break;
	}
	
	while (y - (2 * m) > 0) {
		ll nx, ny;
		nx = x;
		ny = y - (2 * m);
		if (check_poll (nx, ny))
			x = nx, y = ny;
		else
			break;
	}
	cout << "solution " << x + (2 * m) + (m / 2) << " " << y + (2 * m) + (m / 2) << "\n";
	cout.flush();
	return 0;
}