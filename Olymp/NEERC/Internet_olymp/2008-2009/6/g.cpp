#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set <pair <ll, ll> > Set;

inline bool limit (const ll &a, const ll &b) {
	return pow (a, b) > 1e18;
}

inline ll bin_pow (const ll &a, const int &b) {
	if (b == 0) {
		return 1;
	}
	if (b & 1)
		return a * bin_pow (a, b - 1);
	ll c = bin_pow (a, b / 2);
	return c * c;
}

int main () {

	freopen ("power.in", "r", stdin);
	freopen ("power.out", "w", stdout);

	ll x;
	
	cin >> x;

	if (x < 1e5) {
		for (int i = 2; i <= 1e3; ++i)
			for (int j = 2; !limit (i, j); ++j)
				if (bin_pow (i, j) == x)
					Set.insert (make_pair (i, j));
	} else {
		for (int i = 2; i <= 4; ++i) {
			ll y = pow (x, 1.0 / i) - 10;
			ll z = y + 20;
			for (; y <= z; ++y)
				if (!limit (y, i) && bin_pow (y, i) == x)
					Set.insert (make_pair (y, i));
		}
		for (int i = 2; i <= 1e5; ++i)
			for (int j = 2; !limit (i, j); ++j)
				if (bin_pow (i, j) == x)
					Set.insert (make_pair (i, j));
	}
	
	
	cout << Set.size () << "\n";

	for (auto it : Set)
		cout << it.first << " " << it.second << "\n";

	return 0;
}