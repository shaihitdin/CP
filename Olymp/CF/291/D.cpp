#include <bits/stdc++.h>

using namespace std;

const int sz = 1 << 17, N = 1e5 + 10;
int t[6][1 << 18];
int n, m, k, a[N][6];

inline void upd (const int &lvl, int x, const int &to) {
	x += sz;
	t[lvl][x] = to;
	for (x >>= 1; x; x >>= 1)
		t[lvl][x] = max (t[lvl][x << 1], t[lvl][(x << 1) + 1]);
}

inline int get (const int &lvl, int l, int r) {
	int res = 0;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) {
			res = max (t[lvl][l], res);
			++l;
		}
		if (!(r & 1)) {
			res = max (t[lvl][r], res);
			--r;
		}
		if (l > r)
			break;
	}
	return res;
}

int ans[6];

int main () {
    #ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif
	
	ios_base :: sync_with_stdio (0);
	
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];	

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			upd (j, i, a[i][j]);
	int mx = -1;
	for (int i = 1; i <= n; ++i) {
		int l = i - 1, r = n + 1;
		while (r - l > 1) {
			int mid = (r + l) >> 1;
			int sum = 0;
			for (int j = 1; j <= m; ++j)
				sum += get (j, i, mid);
			if (sum > k)
				r = mid;
			else
				l = mid;
		}
		if (l - i + 1 > mx) {
			for (int j = 1; j <= m; ++j)
				ans[j] = get (j, i, l);
			mx = l - i + 1;
		}
	}
	for (int i = 1; i <= m; ++i)
		cout << ans[i] << " ";
	return 0;
}