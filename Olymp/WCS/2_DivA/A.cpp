#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 100, oo = 1e9;

bool banned[N];

int sz[N], d[N], u[N];
vector <int> vertex;
vector <pair <int, int> > g[N], hue[N];
int ans[N];
int lul;

inline void dfs (int v, int p) {
	sz[v] = 1;
	vertex.emplace_back (v);
	for (auto to : g[v]) {
		if (to.first == p || banned[to.first])
			continue;
		dfs (to.first, v);
		sz[v] += sz[to.first];
	}
}

inline int get_root (int v, int p) {
	for (auto to : g[v]) {
		if (to.first == p || banned[to.first])
			continue;
		if (sz[to.first] * 2 >= sz[v])
			return get_root (to.first, v);
	}
	return v;
}

inline void dfs2 (int v, int p, int col) {
	int val = 0;
	if (p == -1)
		u[v] = ++val;
	else
		u[v] = col;
	for (auto to : g[v]) {
		if (to.first == p || banned[to.first])
			continue;
		d[to.first] = min (d[v], to.second);
		if (p == -1)
			dfs2 (to.first, v, ++val);
		else
			dfs2 (to.first, v, col);
	}
}

inline void YO (int root) {
	if (banned[root])
		return;
	vertex.clear ();
	dfs (root, -1);
	root = get_root (root, -1);
	d[root] = oo;
	dfs2 (root, -1, -100);
	for (auto v : vertex)
		for (auto q : hue[v])
			if (u[q.first] && u[q.first] != u[v])
				ans[q.second] = min (d[v], d[q.first]);
	for (auto v : vertex)
		u[v] = sz[v] = 0, d[v] = oo;
	banned[root] = 1;
	for (auto to : g[root])
		YO (to.first);
}

int main () {

	#ifdef BROKEN
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
		
	int n, q;
	
	cin >> n;
	
	for (int i = 2; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back (make_pair (i, y));
		g[i].emplace_back (make_pair (x, y));
	}

	cin >> q;

	for (int i = 1; i <= q; ++i) {
		int x, y;
		cin >> x >> y;
		hue[x].emplace_back (make_pair (y, i));
	}
	
	YO (1);

	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}