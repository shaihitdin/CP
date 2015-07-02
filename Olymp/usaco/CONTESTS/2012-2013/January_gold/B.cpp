#include <bits/stdc++.h>

using namespace std;

const int N = 60, inf = 1e6;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

typedef pair <int, int> pii;

int n, m, c[N][N];

char a[N][N];

int dist[N][N];

int dp[(1 << 16)][16];

inline bool can (const int &i, const int &j) {
	return 1 <= i && i <= n && 1 <= j && j <= m;
}

inline void dfs (const int &i, const int &j, const int &color) {
	c[i][j] = color;
	for (int it = 0; it < 4; ++it) {
		int n_i = i + dx[it], n_j = j + dy[it];
		if (can (n_i, n_j) && !c[n_i][n_j] && a[n_i][n_j] == 'X')
			dfs (n_i, n_j, color);
	}
}

inline bool bit (const int &mask, const int &pos) {
	return (mask >> pos) & 1;
}

int main () {

	freopen ("island.in", "r", stdin);
	freopen ("island.out", "w", stdout);

	scanf ("%d%d\n", &n, &m);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			a[i][j] = getchar ();
		}
		getchar ();
	}

	int cnt (0);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (!c[i][j] && a[i][j] == 'X')
				dfs (i, j, ++cnt);

	for (int i = 1; i <= cnt; ++i)
		for (int j = 1; j <= cnt; ++j)
			dist[i][j] = inf;
			
	set <pair <int, pii> > Set;
	int d[N][N];
	for (int color = 1; color <= cnt; ++color) {
	    
	    for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (c[i][j] == color)
					d[i][j] = 0, Set.insert (make_pair (0, pii (i, j)));
				else
					d[i][j] = inf;
		
		while (Set.size ()) {
			int i = Set.begin () -> second.first, j = Set.begin () -> second.second;
			Set.erase (Set.begin ());
			for (int it = 0; it < 4; ++it) {
				int n_i = i + dx[it], n_j = j + dy[it];
				if (a[n_i][n_j] == '.')
					continue;
				if (can (n_i, n_j) && d[n_i][n_j] > d[i][j] + (a[n_i][n_j] == 'S')) {
					Set.erase (make_pair (d[n_i][n_j], pii (n_i, n_j)));
					d[n_i][n_j] = d[i][j] + (a[n_i][n_j] == 'S');
					Set.insert (make_pair (d[n_i][n_j], pii (n_i, n_j)));
				}
			}
		}
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			    if (a[i][j] == 'X')
					dist[color][c[i][j]] = min (dist[color][c[i][j]], d[i][j]);
	}

	/*
	for (int k = 1; k <= cnt; ++k)
		for (int i = 1; i <= cnt; ++i)
			for (int j = 1; j <= cnt; ++j)
				dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
	*/

	for (int i = 0; i < (1 << cnt); ++i)
		for (int j = 0; j < cnt; ++j)
			dp[i][j] = inf;

	for (int i = 0; i < cnt; ++i)
		dp[(1 << i)][i] = 0;
	
	for (int i = 0; i < (1 << cnt); ++i)
		for (int j = 0; j < cnt; ++j)
			if (bit (i, j))
				for (int k = 0; k < cnt; ++k)
					if (!bit (i, k))
						dp[i | (1 << k)][k] = min (dp[i | (1 << k)][k], dp[i][j] + dist[j + 1][k + 1]);

	int ans = inf;

	for (int i = 0; i < cnt; ++i)
		ans = min (ans, dp[(1 << cnt) - 1][i]);

	printf ("%d", ans);

	return 0;
}