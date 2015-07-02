#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf = 1e9;

ll n, k;

ll mxb = 2, mxd = 0;

inline int cnt (const int &base) {
	if (base == 1)
		return -inf;
	int res = 0;
	for (ll x = n; x && x % base == k; ++res, x /= base);
	return res;
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	cin >> n >> k;

	if (n == k) {
		cout << n + 1 << " " << 1;
		return 0;
	}


	for (int base = 1; base <= 1000000; ++base) {
		int res = cnt (base);
		if (mxd < res)
			mxb = base, mxd = res;
	}
	
	
	/*
	if (k != 0 && (n - k) % k == 0 && mxd < 2)
		mxb = (n - k) / k, mxd = 2;
	*/

	ll n_n = n - k;
	
	for (ll i = 1; i * i <= n_n; ++i) {
		if ((n_n) % i != 0)
			continue;
		int res1 = cnt (i);
		int res2 = cnt (n_n / i);
		if (res1 > mxd)
			mxb = i, mxd = res1;
		if (res2 > mxd)
			mxb = n_n / i, mxd = res2;
	}

	cout << mxb << " " << mxd << "\n";

	return 0;
}