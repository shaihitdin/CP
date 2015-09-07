#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int t;
	
	cin >> t;

	while (t--) {
		ll n, k;
		cin >> n >> k;
		ll need = 0, left_in = 0;
		for (int i = 1; i <= n; ++i) {
			ll x;
			cin >> x;
			ll tmp = min (x, left_in);
			x -= tmp;
			left_in -= tmp;
			if (left_in == 0) {
				need += x / k;
				if (x % k != 0) {
					++need;
					left_in = k - (x % k);
				}
			}
			if (i < n && left_in > 0)
				--left_in;
		}
		cout << need << "\n";
	}

	return 0;
}