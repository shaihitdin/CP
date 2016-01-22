#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;

int d[N], d2[N];
int p[N], len[N];
bool u[N];
vector <int> s, g[N];
int n, m, q;
int sz[N];

inline int get_p (int v) {
	return p[v] = (v == p[v]) ? v : get_p (p[v]);
}

inline void Merge (int a, int b) {
	a = get_p (a), b = get_p (b);
	if (a == b)
		return;
	if (sz[b] > sz[a])
		swap (a, b);
	p[b] = a;
	len[a] = max (len[a], (len[a] + 1) / 2 + 1 + (len[b] + 1) / 2);
	len[a] = max (len[a], len[b]);
	if (sz[a] == sz[b])
		++sz[a];
}

inline void dfs (int v, int p) {
	u[v] = 1;
	s.emplace_back (v);
	for (int to : g[v]) {
		if (to == p)
			continue;
		d[to] = d[v] + 1;
		dfs (to, v);
	}
}

inline void dfs2 (int v, int p) {
	for (int to : g[v]) {
		if (to == p)
			continue;
		d2[to] = d2[v] + 1;
		dfs2 (to, v);
	}
}


int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m >> q;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back (y);
		g[y].emplace_back (x);
	}

	for (int i = 1; i <= n; ++i)
		p[i] = i, len[i] = 0;
	
	for (int i = 1; i <= n; ++i) {
		if (!u[i]) {
			s.clear ();
			dfs (i, -1);
			int mxv = i;
			for (auto v : s)
				if (d[mxv] < d[v])
					mxv = v;
			dfs2 (mxv, -1);
			for (auto v : s)
				len[i] = max (len[i], d2[v]);
			for (auto v : s)
				p[v] = i;
			if (s.size () > 1)
				sz[i] = 1;
		}
	}
	
	while (q--) {
		int q_type;
		cin >> q_type;
		if (q_type == 1) {
			int x;
			cin >> x;
			cout << len[get_p (x)] << "\n";
		} else {
			int x, y;
			cin >> x >> y;
			Merge (x, y);
		}
	}
	
	return 0;

}