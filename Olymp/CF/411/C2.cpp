#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 100;
bool u_c[N], u_v[N];
set <int> colors;
set <int> a[N], b[N];
vector <int> g[N];
int n, m;
int ans[N], c_s;

inline void dfs (int v, int pp) {
	if (u_v[v]) {
		for (int to : g[v]) {
			if (to == pp)
				continue;
			dfs (to, v);
		}
		return;
	}
	if (a[v].size ()) {
		int c = *a[v].begin ();
		for (auto it : b[c])
			u_v[it] = 1;
		u_c[c] = 1;
		ans[c] = c_s;
		for (auto it : b[c])
			a[it].erase (c);
	}
	for (int to : g[v]) {
		if (to == pp)
			continue;
		dfs (to, v);
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int x;
			cin >> x;
			a[i].insert (x);
			b[x].insert (i);
		}
	}	
	
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back (y);
		g[y].emplace_back (x);
	}
	
	
	
	for (int i = 1; i <= m; ++i) {
		if (!u_c[i]) {
			ans[i] = ++c_s;
			for (auto it : b[i])
				u_v[it] = 1;
			u_c[i] = 1;
			for (auto it : b[i])
				a[it].erase (i);
			dfs (*b[i].begin (), 0);

		}
	}

	cout << c_s << "\n";

	for (int i = 1; i <= m; ++i)
		cout << ans[i] << " ";
	return 0;
}