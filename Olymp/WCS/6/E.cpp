#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100, bpr = 1e9 + 7;

//vector <int> g[N];
vector <pair <int, int> > f[N];
int lp[N];

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

int c[N], sum[N];
int d[N][1 << 7], cnt[N][1 << 7];

inline int bin_pow (int x, int y) {
	if (!y)
		return 1;
	if (y & 1)
		return (bin_pow (x, y - 1) * 1ll * x) % bpr;
	int c = bin_pow (x, y / 2);
	return (c * 1ll * c) % bpr;
}

inline vector <pair <int, int> > factorize (int x) {
	vector <pair <int, int> > res;
	while (x > 1) {
		int y = lp[x];
		int cnt = 0;
		while (lp[x] == y) {
			++cnt;
			x /= y;
		}
		res.emplace_back (make_pair (y, cnt));
	}
	return res;
}

int main () {
    #ifdef LOCAL
    freopen ("in", "r", stdin);
    #endif

	int n;
	cin >> n;

	for (int i = 2; i <= n; ++i)
		if (!lp[i])
			for (int j = i; j <= n; j += i)
				if (!lp[j])
					lp[j] = i;
	
	for (int i = 2; i <= n; ++i) {
		f[i] = factorize (i);
		sort (f[i].begin (), f[i].end ());
	}
	
	for (int i = 2; i <= n; ++i) {
		for (int j = i; j <= n; j += i) {
			int mask = 0;
			for (auto it : f[i])
				if (binary_search (f[j].begin (), f[j].end (), it))
					mask |= (1 << (lower_bound (f[j].begin (), f[j].end (), it) - f[j].begin ()));
			++cnt[j][mask];
		}
	}

	for (int i = 2; i <= n; ++i) {
		for (int mask = 0; mask < (1 << f[i].size ()); ++mask) {
			add (d[i][mask], (bin_pow (2, cnt[i][mask]) + bpr - 1) % bpr);
			for (int k = mask; k; --k, k &= mask) {
				if (k < (mask ^ k))
					continue;
				add (d[i][mask], (d[i][k] * 1ll * d[i][mask ^ k]) % bpr);
			}
		}
		c[i] = d[i][(1 << f[i].size ()) - 1];
		add (c[i], c[i]);
	}
	

	int ans = 2;

	for (int i = 2; i <= n; ++i)
		add (ans, c[i]);
	
	cout << ans;	
	return 0;
}