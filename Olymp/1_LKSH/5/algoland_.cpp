#include <bits/stdc++.h>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef pair <int, int> pii;

const int N = 1e4 + 100, M = 1e5 + 100, inf = 1e9 + 100;

vector <pair <int, int> > g[N];
int n, m, a, b;
int d[3][N], p[3][N], pe[3][N];
set <pair <int, int> > Set;

int main () {
	freopen ("algoland.in", "r", stdin);
	freopen ("algoland.out", "w", stdout);

	scanf ("%d%d", &n, &m);

	for (int i = 1; i <= m; ++i) {
		int x, y, z;
		scanf ("%d%d%d", &x, &y, &z);
		g[x].push_back (pii (y, z));
		g[y].push_back (pii (x, z));
	}

	scanf ("%d%d", &a, &b);

	for (int i = 1; i <= n; ++i)
		d[1][i] = d[2][i] = inf;

	d[1][a] = 0;
	d[2][b] = 0;
	Set.insert (pii (0, a));
	
	while (Set.size ()) {
		int v = Set.begin () -> second;
		Set.erase (Set.begin ());
		for (auto it : g[v]) {
			int to = it.first, edge = it.second;
			if (d[1][to] > max (d[1][v], edge)) {
				Set.erase (pii (d[1][to], to));
				d[1][to] = max (d[1][v], edge);
				p[1][to] = v;
				pe[1][to] = edge;
				Set.insert (pii (d[1][to], to));
			}
		}
	}
	
	Set.insert (pii (0, b));

	while (Set.size ()) {
		int v = Set.begin () -> second;
		Set.erase (Set.begin ());
		for (auto it : g[v]) {
			int to = it.first, edge = it.second;
			if (d[2][to] > max (d[2][v], edge)) {
				Set.erase (pii (d[2][to], to));
				d[2][to] = max (d[2][v], edge);
				p[2][to] = v;
				pe[2][to] = edge;
				Set.insert (pii (d[2][to], to));
			}
		}
	}
		
	int ans = inf * 2 + 10;


	for (int i = 1; i <= n; ++i) {
		int v = i;
		int ans1 = 0, ans2 = 0;
		while (v != a) {
			if (ans1 < pe[1][v])
				ans1 = pe[1][v];
			else if (ans2 < pe[1][v])
				ans2 = pe[1][v];
			v = p[1][v];
		}
		v = i;
		while (v != b) {
			if (ans1 < pe[2][v])
				ans1 = pe[2][v];
			else if (ans2 < pe[2][v])
				ans2 = pe[2][v];
			v = p[2][v];
		}
		cerr << i << " " << ans1 << " " << ans2 << "\n";
		ans = min (ans, ans1 + ans2);
	}
	
	printf ("%d", ans);

	return 0;
}