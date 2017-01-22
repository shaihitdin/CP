#include <bits/stdc++.h>

using namespace std;

const int bpr = 1e9 + 7, sz = 1 << 17, N = 1e5 + 100;

int dp[sz + sz + 100], a[N];

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

inline void upd (int x, int delta) {
	add (dp[x += sz], delta);
	while (x >>= 1)
		add (dp[x] = dp[x + x], dp[x + x + 1]);
}

inline int get (int l, int r) {
	int res = 0;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)	add (res, dp[l++]);
		if (!(r & 1))	add (res, dp[r--]);
		if (l > r)	break;
	}
	return res;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int test;

	cin >> test;

	while (test--) {
		int n;
		cin >> n;
		vector <int> cc;	//COMPRESSED VALS
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			cc.push_back (a[i]);
		}

		//COMPRESSION + NULLING FROM PREVIOUS TEST
		sort (cc.begin (), cc.end ());
		cc.resize (unique (cc.begin (), cc.end ()) - cc.begin ());
		for (int i = 0; i < cc.size (); ++i)
			upd (i, bpr - get (i, i));

		for (int i = 1; i <= n; ++i) {
			int sum = get (0, lower_bound (cc.begin (), cc.end (), a[i]) - cc.begin () - 1);	/// ALL SEQUENCES THAT ENDS WITH AN ELEMENT SMALLER THAN OURS CAN BE EXTENDED BY US
			add (sum, 1);	/// SEQUENCES CONTAINING ONLY US
			upd (lower_bound (cc.begin (), cc.end (), a[i]) - cc.begin (), sum);	/// UPDATE DP VALUE
		}

		cout << get (0, cc.size () - 1) << "\n"///ALL SEQUENCES
	}
	return 0;
}