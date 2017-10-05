#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = 2e5 + 100, sz = (1 << 18);

int n, m, a[N], t[sz + sz + 100], st[N], f[N], q[N], add[30][N];

inline void upd (int x, int delta) {
	t[x += sz] = delta;
	while (x >>= 1)	t[x] = (t[x + x] & t[x + x + 1]);
}

inline int get (int l, int r) {
	int res = t[l + sz];
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)	res &= t[l++];
		if (!(r & 1)) res &= t[r--];
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
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		cin >> st[i] >> f[i] >> q[i];
		for (int j = 0; j < 30; ++j)
			if (bit (q[i], j))
				add[j][st[i]]++, add[j][f[i] + 1]--;
	}
	
	for (int step = 0; step < 30; ++step) {
		int now = 0;
		for (int i = 1; i <= n; ++i) {
			now += add[step][i];
			if (now > 0)
				a[i] |= (1ll << step);
		}	
	}
	
	for (int i = 1; i <= n; ++i)
		upd (i, a[i]);
	
	for (int i = 1; i <= m; ++i) {
		if (get (st[i], f[i]) != q[i]) {
			cout << "NO";
			return 0;
		}
	}
	
	cout << "YES\n";

	for (int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	
	return 0;
}