#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 610;

int a[N];
int u[N];
int p[N], p2[N];
vector <int> g[N];
int d[N][N];
int v, e, n, k;

inline bool dfs (int v) {
	if (u[v])
		return 0;
	u[v] = 1;
	for (auto to : g[v]) {
		if (!p[to] || dfs (p[to])) {
			p[to] = v;
			p2[v] = to;
			return 1;
		}
	}
	return 0;
}

int main () {

	#ifdef LOCAL
	freopen ("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio (0);
	cin.tie (0);

	cin >> v >> e >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 1; i <= v; ++i)
		for (int j = 1; j <= v; ++j)
			d[i][j] = 1e9;
	for (int i = 1; i <= v; ++i)
		d[i][i] = 0;
	
	for (int i = 1; i <= e; ++i) {
		int a, b, t;
		cin >> a >> b >> t;
		d[a][b] = d[b][a] = min (d[a][b], t);
	}
	
	for (int k = 1; k <= v; ++k)
		for (int i = 1; i <= v; ++i)
			for (int j = 1; j <= v; ++j)
				d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
	
	
	int l = -1, r = 2e6;

	while (r - l > 1) {
		int mid = (r + l) / 2;
		for (int i = 1; i <= n; ++i) {
			g[i].clear ();
			for (int j = 1; j <= v; ++j) {
				if (d[a[i]][j] <= mid) {
					g[i].emplace_back (j);
				}
			}
		}
		int run = 1;
		memset (p, 0, sizeof (p));
		memset (p2, 0, sizeof (p2));
		while (run) {
			memset (u, 0, sizeof (u));
			run = 0;
			for (int i = 1; i <= n; ++i) {
				if (!p2[i] && dfs (i)) {
					run = 1;
				}
			}
		}
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			if (p2[i])
				res++;
		}
		if (res >= k)	r = mid;
		else	l = mid;
	}

	if (r == 2e6)
		cout << -1;
	else
		cout << r;
	return 0;
}