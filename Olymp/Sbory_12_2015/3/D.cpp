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
	int l = -1, r = t + 1;

	while (r - l > 1) {
		int mid = (r + l) >> 1;
		int res = 0;
		for (int i = 0; i <= mid; ++i)
			if (i > 0)
				res += dp[i][n] * (mid / i);
			else
				res += dp[i][n] * k;
		if (res >= k)
			r = mid;
		else
			l = mid;
	}
	
	if (r == t + 1) {
		cerr << "OK";
		int ans = 0;
		for (int i = 0; i <= t; ++i)
			if (i > 0)
				ans += (t / i) * dp[i][n];
			else
				ans += k * dp[i][n];
		ans = min (ans, k);
		cout << ans;
	} else {
		cout << r;
	}
	
	return 0;
}