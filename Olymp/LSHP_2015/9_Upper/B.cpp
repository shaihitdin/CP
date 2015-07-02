#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e4 + 100;

int x[N], y[N];
int n;


inline ll calc2 (const ll &fx, const ll &fy) {
	ll mx = -1;
	for (int i = 1; i <= n; ++i)
		mx = max (mx, abs (x[i] - fx) * 1ll + abs (y[i] - fy));
	return mx;
}

inline int t2 (const ll &fx) {
	ll l = -1e9, r = 1e9;
	while (r - l > 100) {
		ll mid1 = l + ((r - l) / 3), mid2 = r - ((r - l) / 3);
		if (calc2 (fx, mid1) < calc2 (fx, mid2))
			r = mid2;
		else
			l = mid1;
	}
	l -= 100;
	r += 100;
	ll fy = l;
	ll res = calc2 (fx, fy);
	for (; l <= r; ++l) {
		ll tmp_res = calc2 (fx, l);
		if (tmp_res < res)
			res = tmp_res, fy = l;
	}
	return fy;
}

int main () {
	///#ifdef LOCAL
	freopen ("points.in", "r", stdin);
	freopen ("points.out", "w", stdout);
	///#endif

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];

	for (int i = 1; i <= n; ++i) {
		assert (-5 <= x[i] && x[i] <= 5);
		assert (-5 <= y[i] && y[i] <= 5);
	}

	int l = -1e9, r = 1e9;

	while (r - l > 100) {
		ll mid1 = l + ((r - l) / 3), mid2 = r - ((r - l) / 3);
		if (calc2 (mid1, t2 (mid1)) < calc2 (mid2, t2 (mid2)))
			r = mid2;
		else
			l = mid1;
	}
	
	l -= 100;
	r += 100;
	
	ll fx = l;
	ll res = calc2 (fx, t2 (fx));
	
	for (; l <= r; ++l) {
		ll tmp_res = calc2 (l, t2 (l));
		if (tmp_res < res)
			res = tmp_res, fx = l;
	}
	
	cout << fx << " " << t2 (fx);
	
	return 0;
}