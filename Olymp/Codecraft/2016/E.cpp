#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9, N = 200;

vector <int> liste[N];
vector <int> g[N];

int mn_need[N], n;

inline int dfs (int v) {
	if (mn_need[v] != oo)
		return mn_need[v];
	if (v == n)
		return mn_need[v] = oo;
	for (auto to : g[v])
		liste[v].emplace_back (dfs (to));
	sort (liste[v].begin (), liste[v].end ());
	reverse (liste[v].begin (), liste[v].end ());
	mn_need[v] = liste[v].size ();
	for (int i = 0; i < liste[v].size (); ++i)
		mn_need[v] = min (mn_need[v], i + liste[v][i] - 1);
	mn_need[v] = max (mn_need[v], 0);
	return mn_need[v];
}


int main () {
	#ifdef Geodsso
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	int t;

	cin >> t;

	while (t--) {
		int m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			mn_need[i] = oo;
		for (int i = 1; i <= n; ++i)
			g[i].clear (), liste[i].clear ();
		for (int i = 1; i <= m; ++i) {
			int x, y;
			cin >> x >> y;
			g[x].emplace_back (y);
		}
		int win = dfs (1);
		if (win > 0)
			cout << "Jorah Mormont\n";
		else
			cout << "Khal Drogo\n";
	}
	
	return 0;
}