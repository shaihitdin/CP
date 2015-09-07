#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int get_h (const ll &x) {
	for (int i = 61; i >= 0; --i) {
		if ((1ll << i) & (x))
			return i;
	}
	return -1;
}


int main () {

	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);

	ll n;
	
	cin >> n;

	if (n <= 100) {
		ll x = n;
		for (int i = 1; i <= n; ++i) {
			ll h = get_h (x);
			x ^= (1ll << h);
			x <<= 1;
			x |= 1;
		}
		cout << x;
	} else {
		
		cout << ((1ll << (__builtin_popcountll (n))) - 1);
	}

	return 0;
}
