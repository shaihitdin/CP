/**
	Oh, my dear
**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int bpr = 1e9 + 7;

int n, b, k, x;
int cnt[10];

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)
		x -= bpr;
}

inline vector <int> doit (vector <int> a, int pow10) {
	vector <int> c;
	c.resize (x);
	for (int i = 0; i < x; ++i) {
		for (int j = 1; j < 10; ++j) {
			add (c[(i + (j * pow10)) % x], (a[i] * 1ll * cnt[j]) % bpr);
		}
	}
	return c;
}

inline vector <int> doit (vector <int> a, vector <int> b) {
	vector <int> c;
	c.resize (x);
	for (int i = 0; i < x; ++i) {
		for (int j = 0, k = i; j < x; ++k, ++j) {
			if (k == x)
				k = 0;
			add (c[k], (a[i] * 1ll * b[j]) % bpr);
		}
	}
	return c;
}

inline vector <int> bin_pow (vector <int> a, int b) {
	vector <int> c;
	c.resize (x);
	if (b == 0) {
		c[0] = 1;
		return c;
	}
	if (b & 1)
		return doit (bin_pow (a, b - 1), a);
	c = bin_pow (a, b / 2);
	return doit (c, c);
}

int u[110];

int main () {
	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> b >> k >> x;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
	}
	int it = 1;
	int p = 1;
	vector <int> ans;
	ans.resize (x);
	ans[0] = 1;
	if (b <= 2000) {
		for (int i = 1; i <= b; ++i, p = (p * 10) % x) {
			ans = doit (ans, p);
		}
		cout << ans[k];
		return 0;
	}
	for (; !u[p]; ++it, p = (p * 10) % x) {
		u[p] = it;
		ans = doit (ans, p);
	}
	int len = it - u[p];
	--it;
	vector <int> tmp;
	tmp.resize (x);
	tmp[0] = 1;
	for (int i = 1; i <= len; ++i, p = (p * 10) % x)
		tmp = doit (tmp, p);
	int ss = b - it;
	tmp = bin_pow (tmp, ss / len);
	ans = doit (ans, tmp);
	for (int i = 1; i <= (ss % len); ++i, p = (p * 10) % x)
		ans = doit (ans, p);
	cout << ans[k];
	return 0;
}