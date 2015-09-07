#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

int tin[N], tout[N], timer;
int go[N][18], lvl[N];
vector <int> g[N];
vector <int> cc[2];
int a[N];

inline void dfs (const int &v, const int &p) {
	go[v][0] = p;
	tin[v] = ++timer;
	lvl[v] = lvl[p] + 1;
	for (int i = 1; i < 18; ++i)
		go[v][i] = go[go[v][i - 1]][i - 1];
	for (auto to : g[v]) {
		if (to == p)
			continue;
		dfs (to, v);
	}
	tout[v] = ++timer;
}

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

inline int get_p (int v, const int &step) {
	for (int i = 0; i < 18; ++i)
		if (bit (step, i))
			v = go[v][i];
	return v;
}

inline int lca (int a, int b) {
	if (lvl[a] < lvl[b])
		swap (a, b);
	a = get_p (a, lvl[a] - lvl[b]);
	if (a == b)
		return a;
	for (int i = 17; i >= 0; --i)
		if (go[a][i] != go[b][i])
			a = go[a][i], b = go[b][i];
	a = go[a][0];
	return a;
}

inline bool parent (const int &v, const int &u) { // is vertex u is parent of v
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

inline bool cmp (const int &v, const int &u) {
	if (lvl[v] == lvl[u])
		return v < u;
	return lvl[v] > lvl[u];
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			g[x].push_back (y);
			g[y].push_back (x);
		}
		dfs (1, 1);

		int q;

		cin >> q;

		while (q--) {
			int k;
			cin >> k;
			for (int i = 1; i <= k; ++i)
				cin >> a[i];
			int n_lca = a[1];
			for (int i = 2; i <= k; ++i)
				n_lca = lca (n_lca, a[i]);
			int f_type = -1, s_type = -1;
			bool flag = 0;
			for (int i = 1; i <= k; ++i) {
				if (a[i] == n_lca)
					continue;
				int comp = get_p (a[i], lvl[a[i]] - lvl[n_lca] - 1);
				if (f_type == -1 && comp != s_type)
					f_type = comp;
				else if (s_type == -1 && comp != f_type)
					s_type = comp;
				else if (!(f_type == comp || s_type == comp))
					flag = 1;
			}
			if (flag) {
				cout << "No\n";
				continue;
			}
			for (int i = 1; i <= k; ++i) {
				if (a[i] == n_lca)
					continue;
				int comp = get_p (a[i], lvl[a[i]] - lvl[n_lca] - 1);
				if (comp == f_type)
					cc[0].emplace_back (a[i]);
				else
					cc[1].emplace_back (a[i]);
			}

			for (int i = 0; i < 2; ++i) {
				sort (cc[i].begin (), cc[i].end (), cmp);
				for (int j = 0; j + 1 < cc[i].size (); ++j) {
					int v = cc[i][j], u = cc[i][j + 1];
					if (!parent (v, u))
						flag = 1;
				}
			}
			cc[0].resize (0);
			cc[1].resize (0);
			if (flag)
				cout << "No\n";
			else
				cout << "Yes\n";
		}
		
		for (int i = 1; i <= n; ++i) {
			tin[i] = 0;
			tout[i] = 0;
			g[i].resize (0);
			lvl[i] = 0;
			for (int j = 0; j < 18; ++j)
				go[i][j] = 0;
		}
		timer = 0;
	}

	return 0;
}