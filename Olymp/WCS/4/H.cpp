#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int bpr = 1e9 + 7;

int sym_y[10], sym_x[10], centre[10];
ll dp[20][20][2][2];

inline ll g (int l, int r, int flag1, int flag2) { // flag1 -> x, flag2 -> y;
	if (l == r) {
		if (flag1) {
			return 2;
		}
		return 4;
	}
	if (l > r) {
		return 1;
	}
	if (dp[l][r][flag1][flag2] != -1)
		return dp[l][r][flag1][flag2];
	ll res = 0;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			bool ok = 1;
			if (flag1 && flag2)
				ok &= (i == j && sym_y[i]);
			else if (flag1)
				ok &= (sym_x[i] == j);
			else
				ok &= (sym_y[i] && sym_y[j]);
			if (ok)
				res += g (l + 1, r - 1, flag1, flag2);
		}
	}
	return dp[l][r][flag1][flag2] = res;
}

inline ll calc (int l, int r, int flag1, int flag2) {
	//memset (dp, -1, sizeof (dp));
	return g (l, r, flag1, flag2);
}

inline bool leq (vector <int> a) {
	vector <int> b;
	b.resize (a.size ());
	if (flag3) {
		for (int i = 0, j = a.size () - 1; i <= j; ++i, --j) {
			b[i] = a[i];
			b[j] = sym_x[a[i]];
		}
	} else if (flag2) {
		for (int i = 0, j = a.size () - 1; i <= j; ++i, --j) {
			b[i] = a[i];
			b[j] = a[i];
		}
	} else if (flag1) {
	} else {
		return 0;
	}
	for (int i = 0; i < a.size (); ++i) {
		if (a[i] > b[i])
			return 1;
		if (a[i] < b[i])
			return 0;
	}
	return 1;
}

inline ll ans (ll x) {
	vector <int> cc;
	while (x) {
		cc.emplace_back (x % 10);
		x /= 10;
	}
	if (!cc.size ())
		cc.emplace_back (0);
	reverse (cc.begin (), cc.end ());
	ll res = 0;
	for (int i = 0, j = cc.size () - 1, flag1 = 1, flag2 = 1, flag3 = 1; i <= j && (flag1 || flag2); ++i, --j) {
		if (i == j) {
			for (int k = (i == 0 && cc.size () > 1) ? 1 : 0; k < cc[i]; ++k) {
				res += ((flag1 && centre[k]) || (flag2 && sym_y[k]));
			}
		} else {
			for (int k = (i == 0 && cc.size () > 1) ? 1 : 0; k < cc[i]; ++k) {
				for (int k2 = 0; k2 < 10; ++k2) {
					bool n_flag1 = flag1, n_flag2 = flag2, n_flag3 = flag3;
					n_flag1 &= (sym_x[k] == k2);
					n_flag2 &= (sym_y[k] && sym_y[k2]);
					n_flag3 &= (centre[k] && k == k2);
					if (n_flag3)
						res += calc (i + 1, j - 1, 1, 0) + calc (i + 1, j - 1, 0, 1) - calc (i + 1, j - 1, 1, 1);					
					else if (n_flag1 || n_flag2)
							res += calc (i + 1, j - 1, n_flag1, n_flag2);
				}
			}
		}
		flag1 &= (sym_x[cc[i]] != -1);
		flag2 &= (sym_y[cc[i]]);
		flag3 &= (centre[cc[i]]);

		if (i + 1 > j - 1) {
			res += leq (cc, flag1, flag2, flag3);
		}
	}
	cerr << res << " ";
	for (int i = 0; i < cc.size () - 1; ++i) {
		res += calc (0, i, 1, 0) + calc (0, i, 0, 1) - calc (0, i, 1, 1);
		cerr << res << " ";
	}
	cerr << "\n";
	return res;
}

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	memset (sym_x, -1, sizeof (sym_x));
	sym_y[1] = sym_y[3] = sym_y[8] = sym_y[0] = 1;
	sym_x[2] = 5;
	sym_x[5] = 2;
	sym_x[8] = 8;
	sym_x[0] = 0;
	centre[8] = 1, centre[0] = 1;

	ll a, b;

	cin >> a >> b;
	
	if (a != 0)
		cout << (ans (b) - ans (a - 1)) % bpr;
	else
		cout << ans (b) % bpr;

	return 0;
}