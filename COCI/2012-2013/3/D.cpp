#include <iostream>
#include <stdio.h>

using namespace std;

const int N = 1e5 + 1;

typedef long long ll;

ll n, m, a[N];

inline bool ok (const ll &t) {
	ll res = 0;
	for (int i = 1; i <= n; ++i)
		res += (t / a[i]);
	return res >= m;	
}

int main () {

	freopen ("aerodrom.in", "r", stdin);
	freopen ("aerodrom.out", "w", stdout);
	
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	ll l = 0, r = 1e18;
	while (r - l > 1) {
		ll mid = (r + l) >> 1LL;
		if (ok (mid))
			r = mid;
		else
			l = mid;
	}
	cout << r;
	return 0;
}