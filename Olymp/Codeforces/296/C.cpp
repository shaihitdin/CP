#include <bits/stdc++.h>

using  namespace std;

const int N = 2e5 + 100;

multiset <int> g[N];

vector <int> cycle, odd;

inline void dfs (const int &v) {
	while (g[v].size ()) {
		auto to = *g[v].begin ();
		g[v].erase (g[v].begin ());
		g[to].erase (g[to].find (v));
		dfs (to);
	}
	cycle.push_back (v);
}

int main () {
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].insert (y);
		g[y].insert (x);
	}

	for (int i = 1; i <= n; ++i)
		if (g[i].size() & 1)
			odd.push_back (i);
	for (int i = 0; i < odd.size (); i += 2) {
		int v1 = odd[i], v2 = odd[i + 1];
		g[v1].insert (v2);
		g[v2].insert (v1);
	}

	dfs (1);

	if (!(cycle.size() & 1))
		cycle.push_back (cycle[0]);

	cout << cycle.size() - 1 << "\n";

	for (int i = 0; i + 1 < cycle.size (); ++i) {
		int v = cycle[i], to = cycle[i + 1];
		if (i & 1)
			swap (v, to);
		cout << v << " " << to << "\n";
	}
	return 0;
}