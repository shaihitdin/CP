#include <bits/stdc++.h>

using namespace std;

const int LVL = 18;
const int N = 1e5 + 100;

vector <int> go[N][LVL];
int p[N][LVL];
int lvl[N];
vector <int> g[N];
vector <int> res;

inline void dfs (const int &v, const int &par) {
	p[v][0] = par;
	lvl[v] = lvl[par] + 1;
	for (int i = 1; i < LVL; ++i)
		p[v][i] = p[p[v][i - 1]][i - 1];
	for (int i = 1; i < LVL; ++i) {
		go[v][i] = go[v][i - 1];
		for (auto it : go[p[v][i - 1]][i - 1])
			go[v][i].emplace_back (it);
		sort (go[v][i].begin (), go[v][i].end ());
		go[v][i].resize (min ((int)go[v][i].size (), 10));
	}

	for (int to : g[v]) {
		if (to == par)
			continue;
		dfs (to, v);
	}
}

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

inline int get_p (int v, const int &step) {
	for (int i = 0; i < LVL; ++i)
		if (bit (step, i))
			v = p[v][i];
	return v;
}

inline int lca (int a, int b) {
	if (lvl[a] < lvl[b])
		swap (a, b);
	a = get_p (a, lvl[a] - lvl[b]);
	if (a == b)
		return lvl[a];
	for (int i = LVL - 1; i >= 0; --i)
		if (p[a][i] != p[b][i])
			a = p[a][i], b = p[b][i];
	a = p[a][0];
	return lvl[a];
}

inline void get_here (int a, const int &step) {
	for (int i = 0; i < LVL; ++i) {
		if (bit (step, i)) {
			for (auto it : go[a][i])
				res.emplace_back (it);
			sort (res.begin (), res.end ());
			res.resize (min ((int)res.size (), 10));
			a = p[a][i];
		}
	}
}

inline void get_ans (int a, int b) {
	int lvl_lca = lca (a, b);
	get_here (a, lvl[a] - lvl_lca + 1);
	get_here (b, lvl[b] - lvl_lca);

}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int n, m, q;
	
	cin >> n >> m >> q;

	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back (y);
		g[y].emplace_back (x);
	}
	
	for (int i = 1; i <= m; ++i) {
		int c;
		cin >> c;
		go[c][0].emplace_back (i);
		sort (go[c][0].begin (), go[c][0].end ());
		go[c][0].resize (min ((int)go[c][0].size (), 10));
	}
	
	dfs (1, 0);
	
	while (q--) {
		int v, u, a;
		cin >> v >> u >> a;
		res.clear ();
		get_ans (v, u);
		res.resize (min ((int)res.size (), a));
		cout << res.size () << " ";
		for (auto it : res)
			cout << it << " ";
		cout << "\n";
	}
	
	return 0;
}