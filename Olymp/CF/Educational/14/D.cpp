#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

int n, m;
bool u[N];
vector <int> g[N], cc[N];
int a[N];

inline void dfs (int v, int color) {
	if (u[v])
		return;
	u[v] = 1;
	cc[color].emplace_back (v);
	for (auto to : g[v])
		dfs (to, color);
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif
	
	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i =1; i <= m ;++i) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back (y);
		g[y].emplace_back (x);
	}
	
	int cnum = 0;

	for (int i = 1; i <= n; ++i) {
		if (!u[i])
			dfs (i, ++cnum);
	}
	
	for (int i = 1; i <= cnum; ++i) {
		vector <int> vals;
		for (auto v : cc[i]) {
			vals.emplace_back (a[v]);
		}
		sort (vals.begin (), vals.end ());
		sort (cc[i].begin (), cc[i].end ());
		reverse (vals.begin (), vals.end ());
		for (int j = 0; j < cc[i].size (); ++j) {
			a[cc[i][j]] = vals[j];
		}
	}
	
	for (int i =1; i <= n; ++i)
		cout << a[i] << " ";
	
	return 0;
}