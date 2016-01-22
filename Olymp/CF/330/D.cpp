#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100, sz = 1 << 18, bpr = 1e9 + 7;

inline int bin_pow (const int &a, const int &b) {
	if (!b)
		return 1;
	if (b & 1)
		return (bin_pow (a, b - 1) * 1ll * a) % bpr;
	int c = bin_pow (a, b / 2);
	return (c * 1ll * c) % bpr;;
}

vector <pair <int, int> > b[N / 5];
vector <int> queries_b[N / 5];

int t[sz + sz + 100];
int l_p[N];
int n, m;
int a[N], d[N];
int q_l[N], q_r[N];
int calc[N];
int lst[N];

inline void upd (int x, const int &delta) {
	x += sz;
	t[x] = delta;
	while (x >>= 1)
		t[x] = (t[x * 2] * 1ll * t[x * 2 + 1]) % bpr;
}

inline int get (int l, int r) {
	int res = 1;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)
			res = (res * 1ll * t[l++]) % bpr;
		if (!(r & 1))
			res = (res * 1ll * t[r--]) % bpr;
		if (l > r)
			break;
	} 
	return res;
}

int res[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	for (int i = 2; i < N; ++i) {
		if (!l_p[i])
			for (int j = i; j < N; j += i)
				if (!l_p[j])
					l_p[j] = i;
	}
	
	ios_base :: sync_with_stdio (0);
	
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 1; i <= n; ++i) {
		int x = a[i];
		while (x > 1) {
			int y = x;
			int cnt = 0;
			while (l_p[y] == l_p[x]) {
				++cnt;
				x /= l_p[x];
			}
			b[i].emplace_back (make_pair (l_p[y], cnt));
		}
	}	
	
	d[0] = 1;

	for (int i = 1; i <= n; ++i) {
		d[i] = (d[i - 1] * 1ll * a[i]) % bpr;
	}
	
	cin >> m;

	for (int i = 1; i <= m; ++i) {
		cin >> q_l[i] >> q_r[i];
		queries_b[q_l[i]].emplace_back (i);
	}
	
	for (int i = 0; i < N; ++i)
		lst[i] = n + 1;
	
	for (int i = 1; i <= n; ++i)
		upd (i, 1);
	
	for (int i = 1; i < N; ++i)
		calc[i] = ((i - 1) * 1ll * bin_pow (i, bpr - 2)) % bpr;
	
	for (int i = n; i; --i) {
		for (auto it : b[i]) {
			upd (lst[it.first], (get (lst[it.first], lst[it.first]) * 1ll * bin_pow (calc[it.first], bpr - 2)) % bpr);
			upd (i, (get (i, i) * 1ll * calc[it.first]) % bpr);
			lst[it.first] = i;
		}

		for (auto it : queries_b[i]) {
			res[it] = get (i, q_r[it]);
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		res[i] = (res[i] * 1ll * d[q_r[i]]) % bpr;
		res[i] = (res[i] * 1ll * bin_pow (d[q_l[i] - 1], bpr - 2)) % bpr;
		cout << res[i] << "\n";
	}
	
	return 0;
}