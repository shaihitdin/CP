#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

typedef long long ll;

map <int, pair <ll, int> > Mp[N];
vector <int> add[N];
vector <pair <int, int> > g[N];
ll ans[N];

void dfs (int v, int p) {
	for (auto it : add[v])
		++Mp[v][it].second;
	for (auto to : g[v]) {
		if (to.first == p)
			continue;
		dfs (to.first, v);
		if (Mp[v].size () < Mp[to.first].size ()) {
			//swap (Mp[v], Mp[to.first]);
			for (auto it : Mp[to.first]) {
				auto *el = &Mp[v][it.first];
				int cnt1 = it.second.second;
				ll sum1 = it.second.first + to.second * 1ll * cnt1;
				ans[it.first] += cnt1 * el -> first + el -> second * sum1;
				el -> second += cnt1;
				el -> first += sum1;
			}
			//swap (Mp[v], Mp[to.first]);
		} else {
			for (auto it : Mp[to.first]) {
				auto *el = &Mp[v][it.first];
				int cnt1 = it.second.second;
				ll sum1 = it.second.first + to.second * 1ll * cnt1;
				ans[it.first] += cnt1 * el -> first + el -> second * sum1;
				el -> second += cnt1;
				el -> first += sum1;
			}
		}
		Mp[to.first].clear ();
	}
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n, t;
	
	scanf ("%d%d", &n, &t);

	for (int i = 1; i < n; ++i) {
		int x, y, c;
		scanf ("%d%d%d", &x, &y, &c);
		g[x].emplace_back (make_pair (y, c));
		g[y].emplace_back (make_pair (x, c));
	}

	for (int i = 1; i <= t; ++i) {
		int zz;
		scanf ("%d", &zz);
		while (zz--) {
			int x;
			scanf ("%d", &x);
			add[x].emplace_back (i);
		}
	}
	
	dfs (1, 0);
	
	for (int i = 1; i <= t; ++i)
		printf ("%lld\n", ans[i]);
	
	return 0;
}