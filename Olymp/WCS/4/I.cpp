#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ll n, ans = 0;
	
	cin >> n;
	
	for (int i = 1; i <= 1e6; ++i) {
		ll ke = i * 1ll * i * i;
		if (n - ke >= 0) {
			ll z = n - ke;
			ll l = 1, r = min (z + 1, ll (1e9 + 7));
			while (r - l > 1) {
				ll mid = (r + l) >> 1;
				if (mid * mid <= z)
					l = mid;
				else
					r = mid;
			}
			ans += (l * l == z);
		} else {
			break;
		}
	}
	
	cout << ans;
	
	return 0;
}