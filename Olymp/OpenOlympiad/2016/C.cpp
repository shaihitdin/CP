#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 100;

vector <int> cc;
vector <pair <int, int> > g[N], g2[N];
bool u[N];
int p[N];
vector <pair <int, int> > l1, l2;

inline int get_p (int v) {
	return v == p[v] ? v : p[v] = get_p (p[v]);
}

inline void Merge (int a, int b) {
	a = get_p (a), b = get_p (b);
	if (a == b)
		return;
	if (g[a].size () + g2[a].size () > g[b].size () + g2[b].size ()) {
		p[b] = a;
		for (auto to : g2[b])
			g2[a].emplace_back (to);
		for (auto to : g[b])
			g[a].emplace_back (to);
		g2[b].clear (), g[b].clear ();
		g2[b].shrink_to_fit (), g[b].shrink_to_fit ();
	} else {
		p[a] = b;
		for (auto to : g2[a])
			g2[b].emplace_back (to);
		for (auto to : g[a])
			g[b].emplace_back (to);
		g2[a].clear (), g[a].clear ();
		g2[a].shrink_to_fit (), g[a].shrink_to_fit ();
	}
}

inline void dfs (int v, int p) {
	v = get_p (v);
	for (auto u : g[v]) {
		if (get_p (u) != p)
			dfs (u, v);
	}
	for (auto u : g2[v]) {
		
	}
}

int main () {

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
		g[x].emplace_back (make_pair (x, y));
		g[y].emplace_back (make_pair (y, x));
	}

	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g2[x].emplace_back (make_pair (x, y));
		g2[y].emplace_back (make_pair (y, x));
	}
	
	dfs (1);
	
	cout << cc.size () / 4 << "\n";

	for (int i = 0; i < cc.size (); i += 4)
		cout << cc[i] << " " << cc[i + 1] << " " << cc[i + 2] << " " << cc[i + 3] << "\n";
	
	return 0;
}