#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

set <int> all, not_in_root;
multiset <int> colors;
int p[N];

inline int get_p (int v) {

}

inline void dfs_sz (int v, int pp) {
	sz[v] = 1;
	for (auto to : g[v]) {
		if (to == pp || banned[to])
			continue;
		dfs (to, v);
		sz[v] += sz[to];
	}	
}

inline void dfs1 (int v, int pp, int add) {
	if (add == 1) {
		for (int it : a[v])
			colors.insert (it);
	} else {
		for (int it : a[v])
			colors.erase (colors.find (it));
	}
	for (auto to : g[v]) {
		if (banned[to] || to == pp)
			continue;
		dfs1 (to, v, add);
	}
}

inline void dfs2 (int v, int pp) {
	for (int it : a[v]) {
		if (colors.find (it) == colors.end ()) {
		
		}
	}
}

inline void centroid (int v) {
	if (banned[v])
		return;
	dfs_sz (v, v);
	for (int run = 1; run;) {
		run = 0;
		for (auto to : g[v]) {
			if (banned[to] || sz[to] > sz[v])
				continue;
			if (sz[to] * 2 >= sz[v]) {
				run = 1;
				v = to;
			}
		}
	}
	all.clear ();
	not_in_root.clear ();
	colors.clear ();
	for (auto to : g[v]) {
		dfs1 (to, v, 1);
	}
	for (auto to : g[v]) {
		for (auto to2 : g[to]) {
			dfs1 (to2, to, -1);
		}
		for (auto to2 : g[to]) {
			dfs2 (to2, to);
		}
	
	
		for (auto to2 : g[to]) {
			dfs1 (to2, to, 1);
		}
	}


	banned[v] = 1;
	for (auto to : g[v])
		centroid (to);
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= m; ++i)
		p[i] = i;
	
	for (int i = 1; i <= n; ++i) {
		int cc;
		cin >> cc;
		while (cc--) {
			int x;
			cin >> x;
			a[i].emplace_back (x);
		}
		sort (a[i].begin (), a[i].end ());
	}
	
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back (y);
		g[y].emplace_back (x);
	}
	
	centroid (1);
	
	
	return 0;
}