#include <iostream>
#include <assert.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define mkp make_pair
#define F first
#define S second
typedef long long ll;
typedef long double ld;
string s;
const ld inf = 1e9;
ll mid[5], x_change, y_change, k;
ld l, r, x[5], y[5], mx_ans = -inf, mn_ans = inf;
ld get_dist (const pair <ld, ld> &point) {
	return sqrt (((y[2] - point.S) * (y[2] - point.S)) + ((x[2] - point.F) * (x[2] - point.F)));
}
pair <ld, ld> calc (const ll &step) {
	if (step == 0) {
		return mkp (get_dist (mkp (x[1], y[1])), get_dist (mkp (x[1], y[1])));
	}
	ll x_now = x[1] + (x_change * (step - 1)), y_now = y[1] + (y_change * (step - 1));
	ld t_mn, t_mx, get = get_dist (mkp ((ll)x_now, (ll)y_now));
	t_mn = t_mx = get;
	for (auto it : s) {
		if (it == 'L')
			--x_now;
		if (it == 'R')
			++x_now;
		if (it == 'F')
			++y_now;
		if (it == 'B')
			--y_now;
		get = get_dist (mkp ((ll)x_now, (ll)y_now));
		t_mn = min (get, t_mn);
		t_mx = max (get, t_mx);
	}
	return mkp (t_mn, t_mx);
}
int main () {
	#ifndef ONLINE_JUDGE
	freopen ("expgorl.in", "r", stdin);
	freopen ("expgorl.out", "w", stdout);
	#endif
	ios_base :: sync_with_stdio(0);
	cout.precision(10);
	cout << fixed;
	cin >> k;
	assert (0 <= k);
	cin >> s;
	cin >> x[2] >> y[2] >> x[1] >> y[1];
	for (char it : s) {
		if (it == 'L')
			--x_change;
		if (it == 'R')
			++x_change;
		if (it == 'F')
			++y_change;
		if (it == 'B')
			--y_change;
	}
	l = 0;
	r = k;
	while (r - l > 3) {
		mid[1] = l + (r - l) / 3;
		mid[2] = r - (r - l) / 3;
		if (calc (mid[1]).F < calc (mid[2]).F)
			r = mid[2];
		else
			l = mid[1];
	}	
	l -= 1000;
	r += 1000;
	l = max ((ld)0, l);
	r = min ((ld)k, r);
	ll pos;
	for (int i = l; i <= r; ++i) {
		auto ssh = calc(i).F;
		if (mn_ans > ssh)
			pos = i, mn_ans = ssh;
	}
	for (int i = 0; i <= min(1000LL, k); ++i)
		mx_ans = max (mx_ans, calc(i).S);
	for (int i = k; i >= max(k - 1000, 0LL); --i)
		mx_ans = max (mx_ans, calc(i).S);
	cout << mn_ans << " " << mx_ans;
	return 0;
}