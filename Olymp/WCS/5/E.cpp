#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int sz = 1 << 19, bpr = 1e9 + 7, N = 3e5 + 100;

int tin[N], tout[N], lvl[N], timer;
vector <int> g[N];

inline void dfs (int v) {
	tin[v] = ++timer;
	for (auto to : g[v]) {
		lvl[to] = lvl[v] + 1;
		dfs (to);
	}
	tout[v] = timer;
}

inline void add (int &x, int y) {
	x += y;
	if (x >= bpr)	x -= bpr;
	x += bpr;
	if (x >= bpr)	x -= bpr;
}

inline void upd (int t[], int pos, int delta) {
	add (t[pos += sz], delta);
	while (pos >>= 1) {
		t[pos] = t[pos + pos];
		add (t[pos], t[pos + pos + 1]);
	}
}

inline int get (int t[], int l, int r) {
	int res = 0;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1)	add (res, t[l++]);
		if (!(r & 1)) add (res, t[r--]);
		if (l > r)	break;
	}
	return res;
}

int t1[sz + sz + 100], t2[sz + sz + 100];

int main () {
	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, q;
	
	cin >> n;

	for (int i = 2; i <= n; ++i) {
		int x;
		cin >> x;
		g[x].emplace_back (i);
	}

	lvl[1] = 1;

	dfs (1);
	
	cin >> q;

	while (q--) {
		int q_type;
		cin >> q_type;
		if (q_type == 1) {
			int v, x, k;
			cin >> v >> x >> k;
			upd (t1, tin[v], (x + lvl[v] * 1ll * k) % bpr);
			upd (t1, tout[v] + 1, -((x + lvl[v] * 1ll * k) % bpr));
			upd (t2, tin[v], k);
			upd (t2, tout[v] + 1, -k);
		} else {
			int v;
			cin >> v;
			int res = get (t1, 1, tin[v]);
			add (res, -((get (t2, 1, tin[v]) * 1ll * lvl[v]) % bpr));
			cout << res << "\n";
		}
	}	
	
	return 0;
}