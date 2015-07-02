#include <bits/stdc++.h>

using namespace std;

int bpr, q;

inline int b_p (const int &x, const int &y) {
	if (!y)
		return 1;
	if (y & 1)
		return (x * 1ll * b_p (x, y - 1)) % bpr;
	int b = b_p (x, y >> 1);
	return (b * 1ll * b) % bpr;
}

inline int give_it_to_me_baby (const int &x, const int &y) {
	if (bpr <= 1000) {
		for (int i = 0; i < bpr; ++i)
			if (b_p (x, i) == y)
				return i;
		return -1;
	}
	
	map <int, int> mxz, mnz;
	mnz.clear ();
	mxz.clear ();
	int n = sqrt (bpr);
	int ret_val = bpr;

	for (int i = 0; i <= n + 3; ++i) {
		int val = (b_p (x, i) * 1ll * y) % bpr;
		mxz[val] = max (mxz[val], i);
	}

	for (int i = 0; i <= n; ++i) {
		int tmp = b_p (x, n * i);
		if (mxz.count (tmp))
			ret_val = min (ret_val, (n * i - mxz[tmp] + bpr) % (bpr - 1));
	}

	return ret_val == bpr ? -1 : ret_val;
}

int main () {

	freopen ("alot.in", "r", stdin);
	freopen ("alot.out", "w", stdout);

	cin >> bpr >> q;

	for (int i = 1; i <= q; ++i) {
		int x, y;
		cin >> x >> y;
		cout << give_it_to_me_baby (x, y) << "\n";
	}

	return 0;
}