#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

const int N = 4e5 + 100, oo = 1e18;

struct mine {
	int x, radii, id;
};

int ansl[N], ansr[N], ans[N], col[N];
vector <int> g_r[N], g[N], g2[N];
bool u[N];
vector <int> top;
int v_cnt, cc;
mine a[N];

struct node {
	int v;
	node *l, *r;
	node () {
		v = 0;
		l = r = 0;
	}
	node (int known) {
		v = known;
		l = r = 0;
	}
	node (node *Tl, node *Tr) {
		v = ++v_cnt;
		l = Tl, r = Tr;
		g[v_cnt].emplace_back (Tl -> v);
		g[v_cnt].emplace_back (Tr -> v);
	}
} *root;

inline bool operator < (const mine &a, const mine &b) {
	return a.x < b.x;
}

inline node * Build (int Tl, int Tr) {
	if (Tl == Tr)
		return new node (Tl);
	int mid = (Tl + Tr) >> 1;
	return new node (Build (Tl, mid), Build (mid + 1, Tr));
}

inline void add_edge (node *t, int Tl, int Tr, int l, int r, int sx) {
	if (Tl > r || Tr < l)
		return;
	if (l <= Tl && Tr <= r) {
		g[sx].emplace_back (t -> v);
		return;
	}
	int mid = (Tl + Tr) >> 1;
	add_edge (t -> l, Tl, mid, l, r, sx);
	add_edge (t -> r, mid + 1, Tr, l, r, sx);
}

inline void dfs (int v) {
	if (u[v])
		return;
	u[v] = 1;
	for (auto to : g[v])
		dfs (to);
	top.emplace_back (v);
}

inline void dfs2 (int v, int ce) {
	if (col[v])
		return;
	col[v] = ce;
	for (auto to : g_r[v])
		dfs2 (to, ce);
}

inline void calc (int v) {
	if (u[v])
		return;
	u[v] = 1;
	for (auto to : g2[v]) {
		calc (to);
		ansl[v] = min (ansl[v], ansl[to]);
		ansr[v] = max (ansr[v], ansr[to]);
	}
}

main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int t;
	
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].x >> a[i].radii;
			a[i].id = i;
		}
		sort (a + 1, a + n + 1);
		for (int i = 1; i <= 3 * n; ++i)
			g[i].clear (), g_r[i].clear ();
		v_cnt = n;
		root = Build (1, n);
		for (int i = 1; i <= n; ++i) {
			int l, r;
			int l_bin = 0, r_bin = n + 1;
			int val = a[i].x - a[i].radii;
			while (r_bin - l_bin > 1) {
				int mid = (r_bin + l_bin) >> 1;
				if (a[mid].x < val)
					l_bin = mid;
				else
					r_bin = mid;
			}
			l = r_bin;
			l_bin = 0, r_bin = n + 1;
			val = a[i].x + a[i].radii;
			while (r_bin - l_bin > 1) {
				int mid = (r_bin + l_bin) >> 1;
				if (a[mid].x <= val)
					l_bin = mid;
				else
					r_bin = mid;
			}
			r = l_bin;
			add_edge (root, 1, n, l, r, i);
		}
		top.clear ();
		for (int i = 1; i <= v_cnt; ++i)
			u[i] = 0;
		for (int i = 1; i <= v_cnt; ++i)
			dfs (i);
		reverse (top.begin (), top.end ());
		for (int i = 1; i <= v_cnt; ++i) {
			for (auto to : g[i])
				g_r[to].emplace_back (i);
			col[i] = 0;
		}
		cc = 0;
		for (auto v : top)
			if (!col[v])
				dfs2 (v, ++cc);
		for (int i = 1; i <= cc; ++i)
			g2[i].clear ();
		for (int i = 1; i <= v_cnt; ++i) 
			for (auto to : g[i])
				g2[col[i]].emplace_back (col[to]);
		for (int i = 1; i <= cc; ++i)
			u[i] = 0;
		for (int i = 1; i <= cc; ++i)
			ansl[i] = oo, ansr[i] = 0;
		for (int i = 1; i <= n; ++i)
			ansl[col[i]] = min (ansl[col[i]], i), ansr[col[i]] = max (ansr[col[i]], i);
		for (int i = 1; i <= cc; ++i)
			calc (i);
		for (int i = 1; i <= n; ++i) {
			ans[a[i].id] = ansr[col[i]] - ansl[col[i]] + 1;
		}
		for (int i = 1; i <= n; ++i) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}