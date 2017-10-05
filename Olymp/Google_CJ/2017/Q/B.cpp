#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pw10[20];

inline ll rec (ll x, int ps, int lst, ll limit) {
	if (x > limit) {
		return -1;
	}
	if (ps == -1) {
		return x;
	}
	for (int i = 9; i >= lst; --i) {
		x += (pw10[ps] * 1ll * i);
		ll res = rec (x, ps - 1, i, limit);
		if (res != -1)
			return res;
		x -= (pw10[ps] * 1ll * i);
	}
	return -1;
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	int t;

	cin >> t;

	for (ll i = pw10[0] = 1; i <= 18; ++i)
		pw10[i] = pw10[i - 1] * 10ll;
	
	for (int _ = 1; _ <= t; ++_) {
		cout << "Case #" << _ << ": ";
		ll x;
		cin >> x;
		int cnt = 0;
		ll x2 = x;
		while (x2 / 10)
			x2 /= 10, ++cnt;
		
		for (int len = cnt; len >= 0; --len) {
			ll res = rec (0, len, 0, x);
			if (res != -1) {
				cout << res << "\n";
				break;
			}
		}
	}

	return 0;
}