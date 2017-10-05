#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 100;

ll a[N], b[N], sum_a;
	ll p;
	int n;

inline bool ok (ld mid) {
		ld used = 0;
		for (int i = 1; i <= n; ++i) {
			ld need = a[i] * mid;
			need -= b[i];
			need = max (need, (ld)0.0);
			used += need / p;
		}
		return used <= mid;
}
int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> p;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		sum_a += a[i];
	}
	if (sum_a <= p) {
		cout << -1;
		return 0;
	}
	
	ld l = 0, r = 1e18;

	for (int cnt = 0; cnt < 100; ++cnt) {
		ld mid = (r + l) / 2;
		if (ok (mid))
			l = mid;
		else
			r = mid;
	}
	
	
	cout << fixed;
	cout << setprecision (10);
	
	ok (1);
	
	cout << l;
	return 0;
}