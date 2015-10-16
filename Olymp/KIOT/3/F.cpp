#include <bits/stdc++.h>

using namespace std;

map <int, int> cc;

const int N = 6020;

int d[2][N][N];

int ans = 0;

inline void dfs (const int &v, const int &p) {
	for (auto to : g[v]) {
		if (p == to)
			continue;
		dfs (to);
	}
	
	for (auto to : g[v]) {
		for (int i = 1; i <= n; ++i) {
			d[0][v][i] = max (d[0][v][i], d[0][to][i]);
			d[1][v][i] = max (d[1][v][i], d[1][to][i]);
		}
	}

	++d[0][v][a[v]];
	++d[1][v][a[v]];

	for (int i = 1; i <= n; ++i)
		d[0][v][i] = max (d[0][v][i], d[0][v][i - 1]);
	for (int i = n; i >= 1; --i)
		d[1][v][i] = max (d[1][v][i], d[1][v][i + 1]);
	
	
	int pref_d[2][N], suff_d[2][N];

	memset (pref_d, 0, sizeof (pref_d));
	
	for (int i = 0; i < g[v].size (); ++i) {
		int to = g[v][i];
		for (int j = 1; j <= n; ++j) {
		
		}

		for (int i = 1; i <= n; ++i)
			pref_d
		for (int i = n; i >= 1; --i)
	}
	
	reverse (g[v].begin (), g[v].end ());
	
	
	reverse (g[v].begin (), g[v].end ());
	
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	scanf ("%d", &n);


	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cc.insert (a[i]);
	}

	for (auto it = cc.begin (), x = 1; it != cc.end (); ++it, ++x) {
		it.second = x;
	}
	
	for (int i = 1; i <= n; ++i)
		a[i] = cc[a[i]];
	
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back (y);
		g[y].emplace_back (x);
	}
	
	dfs (1);
	
	return 0;
}