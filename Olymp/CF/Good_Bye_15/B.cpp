#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int bpr = 1e9 + 7, oo = 1e9;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ll a, b;
	int ans = 0;
	cin >> a >> b;

	for (int i = 0; i < 60; ++i) {
		ll x = (1ll << i) - 1;
		for (int j = i + 1; j < 60; ++j) {
			x |= (1ll << j);
			if (a <= x && x <= b) {
				++ans;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}