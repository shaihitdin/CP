#include <bits/stdc++.h>

using namespace std;

const int N = 2049, sz = 16;

typedef long long ll;

const ll inf = 1e18;

ll t[sz + sz + 2];

int a[N];
	
int m, n;

/*
inline ll ssmin (const ll &x, const ll &y) {
	if (x < y)
		return x;
	return y;
}

inline void upd (int x, const int &delta) {
	x += sz;
	t[x] = delta;
	for (; x >>= 1;)
		t[x] = ssmin (t[x << 1], t[(x << 1) + 1]);
}

inline ll geet () {
	int v = 1;
	for (; v < sz; ) {
		if (t[v] == t[v << 1])
			v <<= 1;
		else
			v = (v << 1) + 1;
	}
	return v - sz;
}

*/

inline ll calc (const ll &ti) {
	ll res = 0;
	for (int i = 1; i <= m; ++i)
		res += ((ti / a[i]) + 1);
	return res;
}

int main () {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);

	int te;

	cin >> te;

	for (int test = 1; test <= te; ++test) {
		cout << "Case #" << test << ": ";

		cin >> m >> n;
		
		for (int i = 1; i <= m; ++i) {
			cin >> a[i];
		}

		ll l = -1, r = 1e18;
		
		while (r - l > 1) {
			ll mid = (r + l) >> 1;
			if (calc (mid) < n)
				l = mid;
			else
				r = mid;
		}
				
		for (int i = 1; i <= m; ++i)
			n -= (max ((r - 1) / a[i], 0) + 1);
		
		if (test == 5 || test == 6) {
		
		}
		
		for (int i = 1; i <= m; ++i) {
			n -= (r % a[i] == 0);
			if (n == 0) {
				cout << i;
				break;
			}
		}
		cout << "\n";
	}

	return 0;
}