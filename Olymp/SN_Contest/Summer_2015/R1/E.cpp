#include <bits/stdc++.h>

using namespace std;

const int N = 2002;

typedef long long ll;

ll d[201][N];

struct edge {
	int from, to, c, f;
};

vector <edge> g[N];

const ll oo = 1e13;

set <pair <int, int> > Set;

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	int k, n, m;
	cin >> k >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int a, b, dist, fuel;
		cin >> a >> b >> dist >> fuel;
		g[a].push_back ({a, b, dist, fuel});
		g[b].push_back ({b, a, dist, fuel});
	}

	int s, t;
	cin >> s >> t;
	
	for (int i = 0; i <= k; ++i)
		for (int j = 1; j <= n; ++j)
			d[i][j] = oo;
	d[k][s] = 0;
	ll ans = oo;
	for (; k; --k) {
		for (int i = 1; i <= n; ++i)
			Set.insert (make_pair (d[k][i], i));
		while (Set.size ()) {
			int i = Set.begin () -> second;
			Set.erase (Set.begin ());
			for (auto it : g[i]) {
					if (it.f >= k)
						continue;
					if (it.f == 0 && d[k][it.to] > d[k][i] + it.c) {
						Set.erase (make_pair (d[k][it.to], it.to));
						d[k][it.to] = d[k][i] + it.c;
						Set.insert (make_pair (d[k][it.to], it.to));
						continue;
					}
					d[k - it.f][it.to] = min (d[k - it.f][it.to], d[k][i] + it.c);
			}
		}
		ans = min (ans, d[k][t]);
	}
	
	if (ans == oo) {
		cout << -1;
	} else {
		cout << ans;
	}
	
	return 0;
}