#include <bits/stdc++.h>

using namespace std;

#define mkp make_pair

const int inf = 1e9, N = 1e5 + 1;

vector <pair <int, int> > g[N];
int t, n, d, c, di[N], x, y, cost;

int main () {
	
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	scanf ("%d", &t);

	while (t--) {

		scanf ("%d%d%d", &n, &d, &c);
		
		for (int i = 1; i <= n; ++i)
			di[i] = inf;
		di[c] = 0;
		set <pair <int, int> > s;
		for (int i = 1; i <= n; ++i)
			g[i].resize (0);
		for (int i = 1; i <= d; ++i) {
			scanf ("%d%d%d", &x, &y, &cost);
			g[y].push_back (mkp (x, cost));
		}
		s.insert (mkp (0, c));
		while (s.size()) {
			int v = (*s.begin()).second;
			s.erase (s.begin());
			for (auto to : g[v])
				if (di[to.first] > di[v] + to.second) {
					s.erase (mkp (di[to.first], to.first));
					di[to.first] = di[v] + to.second;
					s.insert (mkp (di[to.first], to.first));
				}
		}
		int ans = 0, anst = 0;
		for (int i = 1; i <= n; ++i) {
			if (di[i] != inf)
				++ans, anst = max (anst, di[i]);
		}
		printf ("%d %d\n", ans, anst);
	}

	return 0;
}