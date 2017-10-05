#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int N = 1010;

ld x[N], y[N];

int main () {

	#ifdef LOCAL
	freopen ("in" ,"r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	
	ld ans = 1e18;

	for (int i = 0; i < n; ++i) {
		int prv = (i - 1 + n) % n;
		int nx = (i + 1) % n;
		ld a = y[prv] - y[nx];
		ld b = x[nx] - x[prv];
		ld c = x[prv] * y[nx] - x[nx] * y[prv];
		ld d = fabs (a * x[i] + b * y[i] + c) / sqrt (a * a + b * b);
		//cerr << d << " ";
		ans = min (ans, d / 2);
	}
	
	cout << fixed;
	cout << setprecision (10);
	cout << ans;

	
	return 0;
}