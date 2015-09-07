#include <bits/stdc++.h>

using namespace std;

const int N = 1100;

int st[N], d[N][N], dist[N];
bool hole[N];
vector <int> g[N];

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	int n, m, k;
	
	cin >> n >> m >> k;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back (y);
		g[y].push_back (x);
	}

	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			d[i][j] = N;
		d[i][i] = 0;
		int stq = 0, enq = 0;
		st[enq++] = i;
		while (stq < enq) {
			int v = st[stq++];
			for (auto to : g[v]) {
				if (d[i][to] > d[i][v] + 1) {
					d[i][to] = d[i][v] + 1;
					st[enq++] = to;
				}
			}
		}
	}
	
	
	int best = N, best_v = 0;
	
	for (int i = 1; i <= n; ++i) {
		int tmp = 0;
		for (int j = 1; j <= n; ++j) {
			tmp = max (tmp, d[i][j]);
		}
		if (tmp < best)
			best_v = i, best = tmp;
	}

	--k;
	hole[best_v] = 1;

	for (int i = 1; i <= n; ++i)
		dist[i] = d[i][best_v];
	
	while (k--) {
		int mx_v = 0;
		for (int i = 1; i <= n; ++i) {
			if (dist[i] > dist[mx_v])
				mx_v = i;
		}
		int place = -1;
		for (int i = 1; i <= n; ++i) {
			if (dist[i] + d[i][mx_v] == dist[mx_v] && d[i][mx_v] == dist[mx_v] / 2)
				place = i;
		}
		if (place == -1)
			assert (0);
		hole[place] = 1;
		for (int i = 1; i <= n; ++i)
			dist[i] = min (dist[i], d[i][place]);
	}
	
	int mx_v = 0;
	for (int i = 1; i <= n; ++i) {
		if (dist[i] > dist[mx_v])
			mx_v = i;
	}
	
	for (int i = 1; i <= n; ++i)
		if (hole[i])
			cerr << i << " ";
	
	cout << dist[mx_v];
	return 0;
}