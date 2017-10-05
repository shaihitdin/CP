#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int bpr = 1e9 + 7;


inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

inline vector <vector <int> > operator * (const vector <vector <int> > &a, const vector <vector <int> > &b) {
	vector <vector <int> > c;
	c.resize (b.size ());
	for (int i = 0; i < b.size (); ++i)
		c[i].resize (b.size ());
	for (int k = 0; k < c.size (); ++k) {
		for (int i = 0; i < c.size (); ++i) {
			for (int j = 0; j < c.size (); ++j) {
				c[i][j] = (c[i][j] + a[i][k] * 1ll * b[k][j]) % bpr;
			}
		}
	}
	return c;
}

vector <vector <int> > zero_m;

inline vector <vector <int> > bin_pow (const vector <vector <int> > &a, ll b) {
	if (!b)
		return zero_m;
	if (b % 2 == 1)	
		return bin_pow (a, b - 1) * a;
	auto c = bin_pow (a, b / 2);
	return c * c;
}


vector <ll> cc;
int pre[16], nx[16];
map <ll, int> lim;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	ll n, k;
	cin >> n >> k;

	zero_m.resize (16);
	for (int i = 0; i < 16; ++i) {
		zero_m[i].resize (16);
		zero_m[i][i] = 1;
	}
	
	for (int i = 1; i <= n; ++i) {
		ll st, en;
		int c;
		cin >> st >> en >> c;
		if (i == n)
			en = k;
		cc.emplace_back (st);
		for (int j = max (st, en - 10); j <= en; ++j) {
			cc.emplace_back (j);
			if (!lim.count (j))
				lim[j] = c;
			else
				lim[j] = min (lim[j], c);
		}
		if (!lim.count (st))
			lim[st] = c;
		else
			lim[st] = min (lim[st], c);
	}

	sort (cc.begin (), cc.end ());
	cc.resize (unique (cc.begin (), cc.end ()) - cc.begin ());
	
	nx[0] = 1;

	for (int i = 0; i + 1 < cc.size (); ++i) {
		memcpy (pre, nx, sizeof (nx));
		memset (nx, 0, sizeof (nx));
		if (cc[i] + 1 == cc[i + 1]) {
			for (int j = 0; j <= 15; ++j)
				for (int kk = max (0, j - 1); kk <= min (j + 1, lim[cc[i + 1]]); ++kk)
					add (nx[kk], pre[j]);
		} else {
			assert (lim[cc[i]] == lim[cc[i + 1]]);
			vector <vector <int> > matrix;
			matrix.resize (16);
			for (int i = 0; i < 16; ++i)
				matrix[i].resize (16);
			for (int j = 0; j <= 15; ++j) {
				for (int kk = max (0, j - 1); kk <= min (j + 1, lim[cc[i + 1]]); ++kk) {
					matrix[j][kk] = 1;
				}
			}
			matrix = bin_pow (matrix, cc[i + 1] - cc[i]);
			for (int j = 0; j <= 15; ++j) 
				for (int kk = max (0, j - 1); kk <= min (j + 1, lim[cc[i + 1]]); ++kk)
					add (nx[kk], pre[j] * 1ll * matrix[j][kk] % bpr);
		}
	}	
	
	cout << nx[0];
	
	return 0;
}