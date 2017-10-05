#include <bits/stdc++.h>

using namespace std;

const int N = 50002;

bitset <N> dp[N];
bool u[N];
vector <int> g[N], gr[N], topsort, comp;
int n, m, q, q_type[N * 2], x[N * 2], y[N * 2], id[N];


inline void top_dfs (int v) {
	if (u[v])
		return;
	u[v] = 1;
	for (auto to : g[v])
		top_dfs (to);
	topsort.emplace_back (v);
}

inline void comp_dfs (int v) {
	if (u[v])
		return;
	u[v] = 1;
	comp.emplace_back (v);
	for (auto to : gr[v])
		comp_dfs (to);
}

inline void dfs_ans (int v) {
	if (u[v])
		return;
	u[v] = 1;
	for (auto to : gr[v]) {
		dfs_ans (to);
		dp[v] |= dp[to];
	}
	dp[v][v] = 1;
}

inline void add (int x, int y) {
	g[x].emplace_back (y);
	gr[y].emplace_back (x);
}

int main () {


	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		add (x, y);
	}
	
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> q_type[i];
		if (q_type[i] == 1) {
			cin >> x[i] >> y[i];
			n++;
			if (y[i] == 0) {
				add (x[i], n);
			} else {
				add (n, x[i]);
			}
		} else {
			cin >> x[i] >> y[i];
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		top_dfs (i);
	}
	
	reverse (topsort.begin (), topsort.end ());
	memset (u, 0, sizeof (u));

	int cc = 0;
		
	for (auto v : topsort) {
		comp_dfs (v);
		if (comp.size ()) {
			++cc;
			for (auto u : comp) {
				id[u] = cc;
			}
		}
		comp.clear ();
	}
	
	for (int i = 1; i <= n; ++i)
		gr[i].clear ();
	
	for (int i = 1; i <= n; ++i) {
		for (auto j : g[i]) {
			gr[id[i]].emplace_back (id[j]);
		}
	}
	
	memset (u, 0, sizeof (u));

	for (int i = 1; i <= cc; ++i)
		dfs_ans (i);
	
	for (int i = 1; i <= q; ++i) {
		if (q_type[i] == 2) {
			if (dp[id[x[i]]][id[y[i]]])
				puts ("Yes");
			else
				puts ("No");
		}
	}

	
	return 0;
}