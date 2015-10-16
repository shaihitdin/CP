#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100;

ll a[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ll n, m, k;
	
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	if (n == 1) {
		ll x = min (ll (a[1]), m * k);
		cout << x;
	} else if (n == 2) {
		cout << 0;
	} else if (n & 1) {
		ll mx_can = min (a[1], a[n]);
		ll cnt = m / (n - 1);
		cout << min (mx_can, cnt * k);
	} else {
		cout << 0;
	}
	
	return 0;
}