#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fe first
#define se second
#define eb emplace_back
#define pb push_back

const int oo = 1e9, N = 1e5 + 100;

int d[N], dup[N], c[N], p[N];
vector <int> g[N], g2[N], g1[N];

inline int Merge (int x, int y) {
	if (x == -1 || y == -1)
		return -1;
	if (x == 0 || y == 0)
		return max (x, y);
	if (x != y)
		return -1;
	return x;
}

inline void dfs (int v, int pp) {
	d[v] = Merge (d[v], c[v]);
	for (auto to : g[v]) {
		if (to == pp)
			continue;
		dfs (to, v);
		d[v] = Merge (d[to], d[v]);
	}
}

inline void calc (int v, int pp) {
	g1[v].resize (g[v].size ());
	g2[v].resize (g1[v].size ());
	for (int i = 0; i < g[v].size (); ++i) {
		if (g[v][i] == pp) {
			g1[v][i] = Merge (g1[v][max (i - 1, 0)], g1[v][i]);
			continue;
		}
		g1[v][i] = Merge (g1[v][max (i - 1, 0)], d[g[v][i]]);
	}
	reverse (g[v].begin (), g[v].end ());
	for (int i = 0; i < g[v].size (); ++i) {
		if (g[v][i] == pp) {
			g2[v][i] = Merge (g2[v][max (i - 1, 0)], g2[v][i]);
			continue;
		}
		g2[v][i] = Merge (g2[v][max (i - 1, 0)], d[g[v][i]]);
	}
	reverse (g[v].begin (), g[v].end ());
	reverse (g2[v].begin (), g2[v].end ());
	for (int i = 0; i < g[v].size (); ++i) {
		if (g[v][i] == pp)
			continue;
		int x = 0;
		if (i > 0)
			x = Merge (x, g1[v][i - 1]);
		if (i + 1 < g[v].size ())
			x = Merge (x, g2[v][i + 1]);
		dup[g[v][i]] = Merge (x, c[v]);
		dup[g[v][i]] = Merge (dup[g[v][i]], dup[v]);
		calc (g[v][i], v);
	}
	p[v] = pp;
}


main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n;
	cin >> n;

	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].eb (y);
		g[y].eb (x);
	}
	
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	
	dfs (1, 1);

	calc (1, 1);
	
	for (int v = 1; v <= n; ++v) {
		int flag = 1;
		for (auto to : g[v]) {
			if (to == p[v])
				continue;
			if (d[to] == -1)
				flag = 0;
		}
		if (dup[v] == -1)
			flag = 0;
		if (flag) {
			cout << "YES\n" << v;
			return 0;
		}
	}
	
	cout << "NO\n";
	return 0;
}