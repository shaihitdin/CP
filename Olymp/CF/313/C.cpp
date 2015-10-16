#include <bits/stdc++.h>

using namespace std;

const int N = 3e5, bpr = 1e9 + 7;

int f[N], rev[N];
int d[N];
int n, m, k;

inline int bin_pow (const int &x, const int &y) {
	if (!y)
		return 1;
	if (y & 1)
		return (bin_pow (x, y - 1) * 1ll * x) % bpr;
	int bb = bin_pow (x, y >> 1);
	return (bb * 1ll * bb) % bpr;
}

pair <int, int> p[N];

inline int cnk (const int &k, const int &n) {
	int res = f[n];
	res = (res * 1ll * rev[k]) % bpr;
	res = (res * 1ll * rev[n - k]) % bpr;
	return res;
}

int main () {
	
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	f[0] = 1;

	for (int i = 1; i < N; ++i) {
		f[i] = (f[i - 1] * 1ll * i) % bpr;
	}

	for (int i = 0; i < N; ++i)
		rev[i] = bin_pow (f[i], bpr - 2);

	cin >> n >> m >> k;

	for (int i = 1; i <= k; ++i)
		cin >> p[i].first >> p[i].second;
	
	p[k + 1].first = n;
	p[k + 1].second = m;
	
	sort (p + 1, p + k + 2);
	
	for (int i = 1; i <= k + 1; ++i) {
		d[i] = cnk (p[i].first - 1, p[i].first - 1 + p[i].second - 1);
		for (int j = 1; j < i; ++j) {
			if (p[i].first < p[j].first || p[i].second < p[j].second)
				continue;
			int tmp = (d[j] * 1ll * cnk (p[i].first - p[j].first, p[i].first - p[j].first + p[i].second - p[j].second)) % bpr;
			d[i] -= tmp;
			d[i] += bpr;
			d[i] %= bpr;
		}
	}
	
	cout << d[k + 1];
	
	return 0;
}