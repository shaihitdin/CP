#include <bits/stdc++.h>

using namespace std;

const int N = 3001, inf = 1e8;

vector <int> d[N], g[N];
int n, m;
int st[N + N], stq, enq;
int s[3], t[3], l[3];

inline vector <int> bfs (const int &start) {
	vector <int> dist;
	dist.resize (n + 1);
	stq = enq = 0;
	st[enq++] = start;
	while (stq < enq) {
		int v = st[stq++];
		for (int to : g[v])
			if (!dist[to] && to != start)
				st[enq++] = to, dist[to] = dist[v] + 1;
	}
	return dist;
}

int main () {
	
	#ifndef ONLINE_JUDGE
	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio (0);
	
	cin >> n >> m;

	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back (y);
		g[y].push_back (x);
	}

	cin >> s[1] >> t[1] >> l[1] >> s[2] >> t[2] >> l[2];
	
	for (int i = 1; i <= n; ++i)
		d[i] = bfs (i);

	int ans = inf;

	if (d[s[1]][t[1]] <= l[1] && d[s[2]][t[2]] <= l[2])
		ans = d[s[1]][t[1]] + d[s[2]][t[2]];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[s[1]][i] + d[i][j] + d[t[1]][j] <= l[1] && d[s[2]][i] + d[i][j] + d[t[2]][j] <= l[2])
				ans = min (ans, d[s[1]][i] + d[i][j] + d[t[1]][j] + d[s[2]][i] + d[t[2]][j]);
			if (d[s[1]][i] + d[i][j] + d[t[1]][j] <= l[1] && d[s[2]][j] + d[i][j] + d[t[2]][i] <= l[2])
				ans = min (ans, d[s[1]][i] + d[i][j] + d[t[1]][j] + d[s[2]][j] + d[t[2]][i]);
		}
	}	
	if (ans == inf)
		cout << -1;
	else
		cout << m - ans;

	return 0;
}