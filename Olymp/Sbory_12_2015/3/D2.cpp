#include <bits/stdc++.h>

using namespace std;

const int N = 20000;

struct edge {
	int v, len, pass;
};

const int oo = 1e8;
int d[3][N];
int n, m, k, t;
vector <edge> g[N], g_rev[N];
int by_dist[N];
vector <int> dp[N];

inline void dijkstra (int d[], int v, vector <edge> g[N]) {
	for (int i = 1; i <= n; ++i)
		d[i] = oo;
	set <pair <int, int> > Set;
	d[v] = 0;
	Set.insert (make_pair (d[v], v));
	while (Set.size ()) {
		int u = Set.begin () -> second;
		Set.erase (Set.begin ());
		for (auto to : g[u]) {
			if (d[to.v] > d[u] + to.len) {
				Set.erase (make_pair (d[to.v], to.v));
				d[to.v] = d[u] + to.len;
				Set.insert (make_pair (d[to.v], to.v));
			}
		}
	}
}
/*
inline bool cmp (const edge &a, const edge &b) {
	return d[1][a.v] + a.len < d[1][b.v] + b.len;
}

inline bool cmp (int v, int u) {
	return d[1][v] < d[1][u];
}
*/

int main () {

    freopen ("evacuation.in", "r", stdin);
    freopen ("evacuation.out", "w", stdout);

	cin >> n >> m >> k >> t;

	for (int i = 1; i <= m; ++i) {
		int a, b, len, pass;
		cin >> a >> b >> len >> pass;
		g[a].push_back ({b, len, pass});
		g_rev[b].push_back ({a, len, pass});
	}

	dijkstra (d[0], 1, g);
	dijkstra (d[1], n, g_rev);


	for (int i = 0; i <= t; ++i)
		dp[i].resize (n + 1);
	
	dp[0][1] = k;

	set <pair <int, int> > Set;
	
	for (int i = 1; i <= n; ++i)
		Set.insert (make_pair (d[1][i], i));
	
	while (1) {
		if (Set.begin () -> first > t)
			break;
		int v = Set.begin () -> second;
		int add = Set.begin () -> first - d[1][v];
		int fdsf = Set.begin () -> first;
		Set.erase (Set.begin ());
		for (auto from : g_rev[v]) {
			if (add - from.len < 0)
				continue;
			int xsd = min (dp[add - from.len][from.v], from.pass);
			dp[add][v] += xsd;
			dp[add - from.len][from.v] -= xsd;
		}
		Set.insert (make_pair (fdsf + 1, v));
	}
/*
	for (int i = 0; i <= t; ++i) {
		for (int it = 1; it <= n; ++it) {
			int j = by_dist[it];
			for (auto from : g_rev[j]) {
				if (i - from.len < 0)
					continue;
				int xsd = min (dp[i - from.len][from.v], from.pass);
				dp[i][j] += xsd;
				dp[i - from.len][from.v] -= xsd;
			}
		}
		/*
		for (int j = 1; j <= n; ++j) {
			sort (g[j].begin (), g[j].end (), cmp);
			for (auto to : g[j]) {
				if (i + to.len > t)
					continue;
				int xsd = min (dp[i][j], to.pass);
				dp[i + to.len][to.v] += xsd;
				dp[i][j] -= xsd;
			}
		}
		*/
/*
	}
*/	
	int l = -1, r = t + 1;

	while (r - l > 1) {
		int mid = (r + l) >> 1;
		int res = 0;
		for (int i = 0; i <= mid; ++i)
			res += dp[i][n] * (mid - i + 1);
		if (res >= k)
			r = mid;
		else
			l = mid;
	}
	
	if (r == t + 1) {
		int ans = 0;
		for (int i = 0; i <= t; ++i)
			ans += (t - i + 1) * dp[i][n];
		cout << ans;
	} else {
		cout << r;
	}
	
	return 0;
}