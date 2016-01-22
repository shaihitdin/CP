#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

vector <int> g[N], g_rev[N];
int d[N], up[N];
int ss;
vector <int> l[2];

inline void dfs (int v, int p, int ss) {
	l[ss].emplace_back (v);
	for (auto to : g[v]) {
		if (to == p)
			continue;
		dfs (to, v, ss);
		d[v] += d[to];
	}
	for (auto to : g_rev[v]) {
		if (to == p)
			continue;
		dfs (to, v, ss);
		d[v] += d[to] + 1;
	}
}

inline void dfs2 (int v, int p) {
	for (auto to : g[v]) {
		if (to == p)
			continue;
		up[to] = up[v] + d[v] - d[to];
		dfs2 (to, v);
	}
	for (auto to : g_rev[v]) {
		if (to == p)
			continue;
		up[to] = up[v] + d[v] - d[to] - 1;
		dfs2 (to, v);
	}
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	int n;
	
	cin >> n;

	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].emplace_back (b);
		g_rev[b].emplace_back (a);
	}
	
	for (int i = 1; i <= n; ++i) {
		dfs (i, i, -1);
	}
	
	int ans (n - 1);
	
	for (int i = 1; i <= n; ++i) {
		for (auto it : g[i]) {
			memset (d, 0, sizeof (d));
			memset (up, 0, sizeof (up));
			l[0].clear ();
			l[1].clear ();
			dfs (i, it, 0);
			dfs2 (i, it);
			dfs (it, i, 1);
			dfs2 (it, i);
			int mn1 = 1e9, mn2 = 1e9;
			for (auto ke : l[0])
				mn1 = min (mn1, d[ke] + up[ke]);
			for (auto ke : l[1])
				mn2 = min (mn2, d[ke] + up[ke]);
			ans = min (ans, mn1 + mn2);
		}
		for (auto it : g_rev[i]) {
			memset (d, 0, sizeof (d));
			memset (up, 0, sizeof (up));
			l[0].clear ();
			l[1].clear ();
			dfs (i, it, 0);
			dfs2 (i, it);
			dfs (it, i, 1);
			dfs2 (it, i);
			int mn1 = 1e9, mn2 = 1e9;
			for (auto ke : l[0])
				mn1 = min (mn1, d[ke] + up[ke]);
			for (auto ke : l[1])
				mn2 = min (mn2, d[ke] + up[ke]);
			ans = min (ans, mn1 + mn2);
		}
	}
	
	cout << ans;
	
	return 0;
}