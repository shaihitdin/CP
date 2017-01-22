/**
	Mom, I'm on someone's monitor!
**/

#include <bits/stdc++.h>

using namespace std;

#define fe first
#define se second
#define mp make_pair
#define eb emplace_back
#define int ll

typedef long long ll;

const int N = 2e5 + 100, bpr = 1e9 + 7, oo = 1e18;

set <pair <int, int> > Set;
int d[N];
int u[N];
int ans = 1;
int tin[N], fup[N], timer;
vector <pair <int, int> > g[N];
vector <int> g2[N], topsort;
int s;
int sz[N];

inline void top4 (int v) {
	if (u[v])
		return;
	u[v] = 1;
	for (auto to : g2[v])
		top4 (to);
	topsort.eb (v);
}

inline void dfs (int v) {
	if (u[v] == 2) {
		sz[v] = 1;
		return;
	}
	if (sz[v])
		return;
	for (auto to : g2[v]) {
		if (u[to] == 1) {
			dfs (to);
			sz[v] += sz[to];
		}
	}
	ans = max (ans, sz[v]);
}

main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int n, m;

	cin >> n >> m >> s;

	for (int i = 1; i <= m; ++i) {
		int from, to, x;
		cin >> from >> to >> x;
		g[from].eb (mp (to, x));
		g[to].eb (mp (from, x));
	}
	
	for (int i = 1; i <= n; ++i)
		d[i] = oo;
	
	d[s] = 0;
	Set.insert (mp (d[s], s));

	while (Set.size ()) {
		int v = Set.begin () -> se;
		Set.erase (Set.begin ());
		for (auto it : g[v]) {
			int to = it.fe;
			int cs = it.se;
			if (d[to] > d[v] + cs) {
				Set.erase (mp (d[to], to));
				d[to] = d[v] + cs;
				Set.insert (mp (d[to], to));
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (auto it : g[i]) {
			int to = it.fe;
			int cs = it.se;
			if (d[i] == d[to] + cs) {
				g2[to].eb (i);
			}
		}
	}
	
	top4 (s);
	
	reverse (topsort.begin (), topsort.end ());

	for (int i = 1; i <= n; ++i)
		u[i] = 0;
	
	u[s] = 1;

	for (auto v : topsort) {
		if (u[v] == 1) {
			for (auto to : g2[v])
				if (u[to])
					u[to] = 2;
				else
					u[to] = 1;
		} else {
			for (auto to : g2[v])
				u[to] = 2;
		}
	}
		
	for (auto v : topsort) {
		dfs (v);
	}
	
	cout << ans;

	return 0;
}