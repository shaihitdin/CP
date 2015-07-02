#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

typedef long long ll;

int m, h[3], a[3], x[3], y[3], size[3];
int cnt[3][N];

inline ll gcd (ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd (b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
 
inline bool find_any_solution (ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	if (b / g > 0) {
		if (x0 < 0)
			x0 += (-x0 / (b / g)) * b / g;
		while (x0 < 0)
			x0 += b / g;
	}	else {
		if (x0 < 0)
			x0 += (-x0 / -(b / g)) * -b / g;
		while (x0 < 0)
			x0 += -b / g;	
	}
	return true;
}

int main () {
    #ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> m;

	for (int i = 1; i <= 2; ++i)
		cin >> h[i] >> a[i] >> x[i] >> y[i];
	
	memset (cnt, -1, sizeof (cnt));
	
	
	for (int i = 1; i <= 2; ++i) {
		int num = 0;
		for (int j = h[i]; cnt[i][j] == -1; j = (j * 1ll * x[i] + y[i]) % m, ++num)
			cnt[i][j] = num;
		size[i] = num;
	}

	if (cnt[1][a[1]] == -1 || cnt[2][a[2]] == -1) {
		cout << "-1";
		return 0;
	}
	
	for (int i = 0, j = h[1], k = h[2]; i <= (int) 1e7; ++i, j = (j * 1ll * x[1] + y[1]) % m, k = (k * 1ll * x[2] + y[2]) % m) {
		if (j == a[1] && k == a[2]) {
			cout << i;
			return 0;
		}
	}
	
	if (cnt[1][a[1]] == cnt[2][a[2]]) {
		cout << cnt[1][a[1]];
		return 0;
	}
	
	ll ans1, ans2, ans3;
	
	if (cnt[1][a[1]] > cnt[2][a[2]]) {
		if (!find_any_solution (-size[1], size[2], cnt[1][a[1]] - cnt[2][a[2]], ans1, ans2, ans3)) {
			cout << -1;
			return 0;
		}
	} else {
		if (!find_any_solution (size[1], -size[2], cnt[2][a[2]] - cnt[1][a[1]], ans1, ans2, ans3)) {
			cout << -1;
			return 0;
		}
	}
	
	if (size[1] * ans1 + cnt[1][a[1]] <= 1e7)
		cout << -1;
	else
		cout << size[1] * ans1 + cnt[1][a[1]];
	
	return 0;
}