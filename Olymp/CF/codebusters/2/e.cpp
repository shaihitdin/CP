#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = 1e5 + 100, sz = (1 << 17);

int a[N];
int t[sz + sz + 100];
int n, m, l[N], r[N], q[N], add[31][N];

inline void upd (int x, int delta) {
	t[x += sz] = delta;
	while (x /= 2)
		t[x] = (t[x + x] & t[x + x + 1]);
}

inline int get (int l, int r) {
	int res = a[l];
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l % 2 == 1)	res = (res & t[l++]);
		if (r % 2 == 0) res = (res & t[r--]);
		if (l > r)	break;
	}
	return res;
}


inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		cin >> l[i] >> r[i] >> q[i];
		for (int j = 0; j < 30; ++j) {
			if (bit (q[i], j))
				continue;
			++add[j][l[i]];
			--add[j][r[i] + 1];
		}
	}
	
	for (int b = 0; b < 30; ++b) {
		for (int now = 0, i = 1; i <= n; ++i) {
			now += add[b][i];
			if (now == 0)
				a[i] |= (1ll << b);
		}
	}
	
	for (int i = 1; i <= n; ++i)
		upd (i, a[i]);
	
	for (int i = 1; i <= m; ++i) {
		if (get (l[i], r[i]) == q[i])
			continue;
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";	
	
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	
	return 0;
}