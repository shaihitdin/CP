#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int N = 60001;

bool u[N];
vector <int> g[N], g_r[N], topsort;
int color[N], in[N], out[N];

inline void dfs (const int &v) {
	u[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (!u[to])
			dfs (to);
	}
	topsort.push_back (v);
}

inline void dfs2 (const int &v, const int &v_col) {
	color[v] = v_col;
	for (int i = 0; i < g_r[v].size(); ++i) {
		int to = g_r[v][i];
		if (!color[to])
			dfs2 (to, v_col);
	}
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int test = 0;
	while (++test) {
		int n, m;
		scanf ("%d%d", &n, &m);
		if (n == 0 && m == 0)
			return 0;

		for (int i = 1; i <= n; ++i) {
			g[i].resize (0);
			g_r[i].resize (0);
		}
		for (int i = 1; i <= m; ++i) {
			int x, y;
			scanf ("%d%d", &x, &y);
			g[x].push_back (y);
			g_r[y].push_back (x);
		}
		memset (u, 0, sizeof (u));
		memset (color, 0, sizeof (color));
		topsort.resize (0);
		for (int i = 1; i <= n; ++i)
			if (!u[i])
				dfs (i);
		reverse (topsort.begin(), topsort.end());
		int csz = 0;
		for (int j = 0; j < topsort.size(); ++j) {
			int i = topsort[j];
			if (!color[i])
				dfs2 (i, ++csz);
		}
		if (csz == 1) {
			printf ("Case %d: The system is already connected.\n", test);
			continue;
		}
		memset (in, 0, sizeof (in));
		memset (out, 0, sizeof (out));
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < g[i].size(); ++j) {
				int to = g[i][j];
				if (color[i] != color[to])
					in[color[i]] = out[color[to]] = 1;
			}
		int left_in = csz, left_out = csz;
		for (int i = 1; i <= csz; ++i)
			left_in -= in[i], left_out -= out[i];
		printf ("Case %d: The minimal number of roads is %d.\n", test, max (left_in, left_out));
	}
}